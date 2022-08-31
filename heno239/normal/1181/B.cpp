#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<int> vec;
typedef vector<string> svec;

struct bigint {
	string s;
	bigint() {};
	bigint(ll n) { s = to_string(n); };
	bigint(string t) { s = t; };
};
bool operator==(const bigint &a, const bigint &b) { return a.s == b.s; };
bool operator==(const bigint &a, const int &b) { return a.s == to_string(b); };
bool operator!=(const bigint &a, const bigint &b) { return !(a == b); };
bool operator!=(const bigint &a, const int &b) { return a != to_string(b); };
bool operator<(const bigint &a, const bigint &b) {
	if (a.s.length() != b.s.length())return a.s.length() < b.s.length();
	return a.s < b.s;
}
bool operator>(const bigint &a, const bigint &b) {
	if (a.s.length() != b.s.length())return a.s.length() > b.s.length();
	return a.s > b.s;
}
bool operator>=(const bigint &a, const bigint &b) {
	return !(a < b);
}
bool operator<=(const bigint &a, const bigint &b) {
	return !(a > b);
}
bigint operator+(const bigint &a, const bigint &b) {
	int len = max(a.s.length(), b.s.length());
	bigint ret; bool f = false;
	rep(i, len) {
		int c = 0;
		if (f)c = 1, f = false;
		int j = a.s.length() - 1 - i;
		if (j >= 0)c += a.s[j] - '0';
		j = b.s.length() - 1 - i;
		if (j >= 0)c += b.s[j] - '0';
		if (c >= 10)f = true, c -= 10;
		ret.s.push_back('0' + c);
	}
	if (f)ret.s.push_back('1');
	reverse(ret.s.begin(), ret.s.end()); return ret;
}
bigint operator+(const bigint &a, const int b) {
	return a + bigint(b);
}
bigint operator-(const bigint &a, const bigint &b) {
	int len = max(a.s.length(), b.s.length());
	bigint ret; bool f = false;
	rep(i, len) {
		int c = 0;
		if (f)c = -1, f = false;
		int j = a.s.length() - 1 - i;
		if (j >= 0)c += a.s[j] - '0';
		j = b.s.length() - 1 - i;
		if (j >= 0)c -= b.s[j] - '0';
		if (c < 0)f = true, c += 10;
		ret.s.push_back('0' + c);
	}
	while (ret.s.size() > 1 && ret.s.back() == '0')ret.s.pop_back();
	reverse(ret.s.begin(), ret.s.end());
	return ret;
}
bigint operator/(const bigint &a, const bigint &b) {
	bigint ret(0);
	bigint ans;
	int len = a.s.length();
	rep(i, len) {
		ret = ret + (a.s[i] - '0');
		int cnt = 0;
		while (ret >= b)++cnt, ret = ret - b;
		ans.s.push_back('0' + cnt);
		if (ret != 0)ret.s.push_back('0');
	}
	rep(i, ans.s.length()) {
		if (ans.s[i] != '0') {
			ans.s.erase(ans.s.begin(), ans.s.begin() + i);
			break;
		}
		if (i == (int)ans.s.length() - 1) {
			ans = 0;
		}
	}
	return ans;
}
bigint operator%(const bigint &a, const bigint &b) {
	bigint ret(0);
	int len = a.s.length();
	rep(i, len) {
		ret = ret + (a.s[i] - '0');
		while (ret >= b)ret = ret - b;
		if (ret != 0 && i < len - 1)ret.s.push_back('0');
	}

	rep(i, ret.s.size()) {
		if (ret.s[i] != '0' || i == ret.s.size() - 1) {
			ret.s.erase(ret.s.begin(), ret.s.begin() + i);
			break;
		}
	}
	return ret;
}
bigint multi(const bigint &a, const int &t) {
	bigint ret;
	int c = 0;
	per(i, a.s.length()) {
		c += (a.s[i] - '0')*t;
		ret.s.push_back('0' + (c % 10));
		c /= 10;
	}
	while (c > 0) {
		ret.s.push_back('0' + (c % 10));
		c /= 10;
	}
	while (ret != 0 && ret.s.back() == '0')ret.s.pop_back();
	reverse(ret.s.begin(), ret.s.end());
	return ret;
}
bigint operator*(const bigint &a, const bigint &b) {
	bigint ret(0);
	int l = b.s.length();
	rep(i, b.s.length()) {
		bigint u = multi(a, (b.s[l - 1 - i] - '0'));
		if (u != 0) {
			rep(j, i)u.s.push_back('0');
		}
		ret = ret + u;
	}
	rep(i, ret.s.size()) {
		if (ret.s[i] != '0' || i == ret.s.size() - 1) {
			ret.s.erase(ret.s.begin(), ret.s.begin() + i);
			break;
		}
	}
	return ret;
}
bigint min(const bigint &a, const bigint &b) {
	if (a < b)return a;
	else return b;
}
bigint max(const bigint &a, const bigint &b) {
	if (a < b)return b;
	else return a;
}

bigint gcd(bigint a, bigint b) {
	if (a < b)swap(a, b);
	while (b>0) {
		bigint r = a % b; a = b; b = r;
	}
	return a;
}
typedef pair<bigint, bigint> bP;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int le = n / 2, ri = (n+1) / 2;
	while (true) {
		if (le == ri) {
			if (s[le] != '0') {
				bigint l = s.substr(0, le);
				bigint r = s.substr(le, n - le);
				l = l + r;
				cout << l.s << endl; return;
			}
		}
		else {
			if (s[le] != '0'&&s[ri] != '0') {
				bigint l = s.substr(0, le);
				l = l+s.substr(le, n - le);
				bigint r = s.substr(0, ri);
				r = r + s.substr(ri, n - ri);
				cout << min(l, r).s << endl; return;
			}
			else if (s[le] != '0') {
				bigint l = s.substr(0, le);
				l = l + s.substr(le, n - le);
				cout << l.s << endl; return;
			}
			else if(s[ri]!='0'){
				bigint r = s.substr(0, ri);
				r = r + s.substr(ri, n - ri);
				cout << r.s << endl; return;
			}
		}
		le--; ri++;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(9);
	//init();
	solve();
	//stop
	return 0;
}