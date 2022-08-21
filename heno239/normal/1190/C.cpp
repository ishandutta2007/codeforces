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
typedef vector<LP> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;


void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	vector<int> loc[2];
	rep(i, n) {
		if (s[i] == '0')loc[0].push_back(i);
		else loc[1].push_back(i);
	}
	//first?
	rep(i, n - k + 1) {
		rep(j, 2) {
			int c = lower_bound(loc[j].begin(), loc[j].end(), i) - loc[j].begin();
			if (c == 0) {
				c = lower_bound(loc[j].begin(), loc[j].end(), i + k) - loc[j].begin();
				if (c == loc[j].size()) {
					cout << "tokitsukaze" << endl; return;
				}
			}
		}
	}
	//second?
	rep(i, n - k + 1) {
		rep(j, 2) {
			int le = loc[j][0];
			if (i <= le && le < i + k) {
				le = lower_bound(loc[j].begin(), loc[j].end(), i + k) - loc[j].begin();
				le = loc[j][le];
			}
			int ri = loc[j].back();
			if (i <= ri && ri < i + k) {
				ri = lower_bound(loc[j].begin(), loc[j].end(), i) - loc[j].begin();
				ri--;
				ri = loc[j][ri];
			}
			//cout << i << " " << j << " " << le << " " << ri << endl;
			if (ri - le >= k) {
				cout << "once again" << endl; return;
			}
		}
	}
	cout << "quailty" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);
	//init();
	solve();
	//stop
		return 0;
}