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
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;
vector<int> G[1 << 17];
bool used[1 << 17];
P p[1 << 17]; int n, m;
int root[1 << 17];
bool ok(int mid) {
	fill(root, root + n, 0);
	rep(i, n) {
		G[i].clear();
	}
	rep(i, mid) {
		G[p[i].first].push_back(p[i].second);
		root[p[i].second]++;
	}
	int r = 0; int cnt = 0;
	rep(i, n) {
		if (!root[i]) {
			cnt++;
			r = i;
		}
	}
	if (cnt != 1)return false;
	rep(i, n - 1) {
		int nex = r;
		cnt = 0;
		rep(j, G[r].size()) {
			root[G[r][j]]--;
			if (!root[G[r][j]]) {
				cnt++; nex = G[r][j];
			}
		}
		if (cnt != 1)return false;
		r = nex;
	}
	return true;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, m) {
		int x, y; cin >> x >> y; x--; y--;
		p[i] = { x,y };
	}
	int le = 0; int ri = m;
	while (ri - le > 1) {
		int mid = (ri + le) >> 1;
		if (ok(mid))ri = mid;
		else le = mid;
	}
	if (!ok(m))ri = -1;
	cout << ri << endl;
		return 0;
}