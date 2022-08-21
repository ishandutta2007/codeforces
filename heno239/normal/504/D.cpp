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

//#define int long long
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
typedef vector<ll> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;



typedef bitset<2001> bt;

bt trans(string s) {
	vector<int> num;
	rep(i, s.size()) {
		num.push_back(s[i] - '0');
	}
	reverse(num.begin(), num.end());
	bt ans;
	for (int k = 0; num.size(); k++) {
		ans[k] = num[0] & 1;
		int sz = num.size();
		for (int i = 0; i<sz - 1; i++) {
			num[i] = (num[i] + (num[i + 1] & 1) * 10) >> 1;
		}
		num.back() >>= 1;
		if (num.back() == 0) num.pop_back();
	}
	return ans;
}

vector<bt> b;
vector<int> fr;

typedef bitset<2000> bt2;
vector<bt2> ids;

vector<int> out[2000];
void add(bt &x,int id) {
	int loc;
	rep(i, 2001) {
		if (x[i]) {
			loc = i; break;
		}
	}
	bt2 ans; ans[id]=1;
	rep(i, b.size()) {
		if (fr[i] > loc) {
			fr.insert(fr.begin() + i, loc);
			b.insert(b.begin() + i, x);
			ids.insert(ids.begin() +i, ans);
			return;
		}
		else if (fr[i] == loc) {
			x ^= b[i];
			ans ^= ids[i];
			for (int j = loc + 1; j <= 2000; j++) {
				if (x[j]) {
					loc = j; break;
				}
			}
			if (loc == fr[i]) {
				rep(j, id) {
					if (ans[j]) {
						out[id].push_back(j);
					}
				}
				return;
			}
		}
	}
	fr.push_back(loc);
	b.push_back(x);
	ids.push_back(ans);
}

void solve() {
	int n; cin >> n;
	vector<bt> m(n);
	rep(i, n) {
		string s; cin >> s;
		m[i] = trans(s);
	}
	//if (n == 2000)return;
	rep(i, n) {
		add(m[i],i);
	}
	rep(i, n) {
		cout << out[i].size();
		if (out[i].size()) {
			rep(j, out[i].size()) {
				cout << " " << out[i][j];
			}
		}
		cout << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	string l = to_string(2), r = to_string(1);
	//cout << dec(l,r) << endl;
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}