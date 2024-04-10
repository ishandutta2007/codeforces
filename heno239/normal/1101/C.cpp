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
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int ans[1 << 18];
typedef pair<P, int> speP;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	rep(aa, t) {
		int n; cin >> n;
		vector<speP> v;
		rep(i, n) {
			int l, r; cin >> l >> r;
			v.push_back({ { l,r },i });
		}
		sort(v.begin(), v.end());
		bool valid = true;
		int z = 0;
		rep(i, n) {
			ans[v[i].second] = z;
			int ri = v[i].first.second;
			while (i + 1 < n&&v[i + 1].first.first <= ri) {
				ri = max(ri, v[i + 1].first.second);
				i++; ans[v[i].second] = z;
			}
			z ^= 1;
		}
		bool exi = false;
		rep(i, n) {
			if (ans[i] == 1)exi = true;
		}
		if (!exi)valid = false;
		if (!valid) {
			cout << -1 << endl;
		}
		else {
			rep(i, n) {
				if (i > 0)cout << " ";
				cout << ans[i]+1;
			}
			cout << endl;
		}
	}
	//stop
	return 0;
}