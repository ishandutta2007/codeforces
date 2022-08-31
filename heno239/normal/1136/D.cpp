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
const ll mod = 1000000007;
typedef long double ld;
const ld INF = (ld)10000000000000;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
map<P, bool> mp;
int p[300001];
int invp[300001];
vector<int> loc[300001];
bool cansk[300001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	rep(i, n) {
		cin >> p[i]; invp[p[i]] = i;
	}
	rep(i, m) {
		int u, v; cin >> u >> v;
		loc[invp[u]].push_back(invp[v]);
		mp[{u, v}] = true;
	}
	int k = p[n - 1];
	int ans = 0;
	per(i, n - 1) {
		if (mp[{p[i], k}]) {
			ans++;
		}
		else {
			bool exi = false;
			per(j, i) {
				if (!mp[{p[j], k}])continue;
				sort(loc[j].begin(), loc[j].end());
				int sta = lower_bound(loc[j].begin(), loc[j].end(), j + 1) - loc[j].begin();
				bool valid = true;
				Rep1(k, j + 1, i) {
					if (cansk[k])continue;
					while (sta < loc[j].size() && loc[j][sta] < k)sta++;
					if (sta == loc[j].size() || loc[j][sta] != k) {
						valid = false; break;
					}
				}
				if (valid) {
					ans++; cansk[j] = true;
				}
			}
			break;
		}
	}
	cout << ans << endl;
	//stop
	return 0;
}