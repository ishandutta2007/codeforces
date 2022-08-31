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
const ld eps = 1e-2;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
const int mn = 300001;
bool used[mn];
vector<int> G[mn];
int z[mn];
queue<int> q;
ll t2[mn];
void init() {
	t2[0] = 1;
	rep(i, mn - 1) {
		t2[i + 1] = t2[i] * 2 % mod;
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	init();
	int t; cin >> t;
	rep(aa, t) {
		int n, m; cin >> n >> m;
		fill(used, used + n, false);
		rep(i, n) {
			G[i].clear();
		}
		rep(i, m) {
			int a, b; cin >> a >> b; a--; b--;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		ll ans = 1;
		rep(i, n) {
			if (used[i])continue;
			used[i] = true;
			z[i] = 0; q.push(i);
			int c[2] = { 1,0 };
			bool valid = true;
			while (!q.empty()) {
				int x = q.front(); q.pop();
				rep(j, G[x].size()) {
					int to = G[x][j];
					if (used[to]) {
						if (z[to] != (z[x] ^ 1))valid = false;
					}
					else {
						used[to] = true;
						z[to] = (z[x] ^ 1);
						c[z[to]]++;
						q.push(to);
					}
				}
			}
			ll csum = (t2[c[0]] + t2[c[1]]) % mod;
			if (!valid)csum = 0;
			ans = ans * csum%mod;
		}
		cout << ans << endl;
	}
	//stop
	return 0;
}