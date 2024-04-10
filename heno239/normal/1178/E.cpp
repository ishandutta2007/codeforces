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
const ll mod = 998244353;
const ll INF = mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<LP> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

void solve() {
	string s; cin >> s;
	int n = s.length();// cout << n << endl;
	int le = 0, ri = n - 1;
	string ansl;
	string ans;

	while (le<=ri) {
		//cout << le << " " << ri << endl;
		if (le == ri) {
			ans += ansl; ans.push_back(s[le]);
			reverse(ansl.begin(), ansl.end());
			ans += ansl;
			cout << ans << endl; return;
		}
		char l = s[le], r = s[ri];
		if (l == r) {
			ansl.push_back(s[le]);
			le++; ri--;
			continue;
		}
		if (ri - le > 2 && s[le + 1] == s[ri - 1]) {
			ansl.push_back(s[le + 1]);
			le += 2; ri -= 2; continue;
		}
		int idle = le + 1;
		while (idle < ri&&s[idle] != r) {
			idle++;
		}
		if (idle - le <= 2) {
			if (idle == ri) {
				ans += ansl; ans.push_back(s[ri]);
				reverse(ansl.begin(), ansl.end());
				ans += ansl;
				cout << ans << endl; return;
			}
			ansl.push_back(r);
			le = idle + 1; ri--; continue;
		}
		int idri = ri - 1;
		while (idri > le&&s[idri] != l) {
			idri--;
		}
		if (idri == le) {
			ans += ansl; ans.push_back(s[le]);
			reverse(ansl.begin(), ansl.end());
			ans += ansl;
			cout << ans << endl; return;
		}
		ansl.push_back(l);
		le++; ri = idri - 1;
	}
	ans += ansl; reverse(ansl.begin(), ansl.end()); ans += ansl;
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}