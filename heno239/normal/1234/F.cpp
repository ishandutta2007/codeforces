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
#include<utility>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<cassert>
#include<random>
#include<unordered_map>
#include<numeric>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define stop char nyaa;cin>>nyaa;

using P = pair<int, int>;
using LP = pair<ll, ll>;

void solve() {
	string s; cin >> s;
	int n = s.size();
	vector<bool> exi(1 << 20);
	vector<int> alf(n);
	rep(i, n)alf[i] = s[i] - 'a';
	exi[0] = true;
	rep(i, n) {
		int ss = 1 << alf[i];
		exi[ss] = true;
		for (int j = i + 1; j < n; j++) {
			if ((ss >> alf[j]) & 1)break;
			ss |= (1 << alf[j]);
			exi[ss] = true;
		}
	}
	vector<int> c(1 << 20);
	rep(i, (1 << 20)){
		if (exi[i]) {
			rep(j, 20)if ((i >> j) & 1)c[i]++;
		}
		rep(j, 20) {
			if ((i >> j) & 1) {
				c[i] = max(c[i], c[i ^ (1 << j)]);
			}
		}
	}
	int ans = 0;
	rep(i, (1 << 20))if (exi[i]) {
		int tmp = 0;
		rep(j, 20)if ((i >> j) & 1)tmp++;
		ans = max(ans, tmp + c[(1 << 20) - 1 - i]);
	}
	cout << ans << endl;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int t; cin >> t;rep(i,t) solve();
	solve();
	stop
		return 0;
}