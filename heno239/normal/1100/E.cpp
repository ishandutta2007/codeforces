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
int n, k;
struct edge {
	int fr,to, cost; int id;
};
int par[1 << 17];
edge e[1 << 17];
vector<edge>G[1 << 17];

int par2[1 << 17];
int cnt[1 << 17];
bool used[1 << 17];
bool can(int mid) {
	fill(cnt, cnt + n, 0);
	fill(used, used + n, false);
	rep(j, k) {
		if(e[j].cost>mid)cnt[e[j].to]++;
	}
	queue<int> q;
	rep(i, n) {
		if(cnt[i]==0)q.push(i);
	}
	while (!q.empty()) {
		int x = q.front(); q.pop();
		used[x] = true;
		rep(j, G[x].size()) {
			int to = G[x][j].to;
			if (used[to])continue;
			par2[G[x][j].id] = x;
			int co = G[x][j].cost;
			if (co > mid) {
				cnt[to]--;
				if (cnt[to] == 0) {
					cnt[to] = mod;
					q.push(to);
				}
			}
		}
	}
	rep(i, n) {
		if (!used[i])return false;
	}
	return true;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	rep(i, k) {
		int x, y, c; cin >> x >> y >> c; x--; y--;
		e[i] = { x,y,c,i };
		G[x].push_back({ x,y,c,i });
		G[y].push_back({ y,x,c,i });
		par[i] = x;
	}
	int le = -1; int ri = mod;
	while (ri - le > 1) {
		int mid = (ri + le) / 2;
		if (can(mid))ri = mid;
		else le = mid;
	}
	vector<int> ans;
	rep(i, k) {
		if (par[i] != par2[i])ans.push_back(i+1);
	}
	cout << ri << " " << ans.size() << endl;
	rep(i, ans.size()) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
	//stop
	return 0;
}