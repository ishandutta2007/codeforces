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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = (ll)(1e+9) + 7;
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
typedef pair<ld, ld> LDP;
int n, m;
struct edge { int to, id; };
vector<edge> G[1 << 18];
int c[1 << 18];
int s[1 << 18];
bool used[1 << 18];
vector<edge> rG[1 << 18];
void maketree(int root) {
	queue<int> q; q.push(root); used[root] = true;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		rep(i,G[x].size()) {
			int to = G[x][i].to;
			if (used[to])continue;
			rG[x].push_back(G[x][i]);
			used[to] = true; q.push(to);
		}
	}
}
void update(int fr, int cur,int id) {
	rep(i, rG[cur].size()) {
		update(cur,rG[cur][i].to,rG[cur][i].id);
	}
	if (fr == cur)return;
	if (s[cur] % 2) {
		if (c[id] == cur) {
			c[id] = fr; s[cur]--; s[fr]++;
		}
		else {
			c[id] = cur; s[fr]--; s[cur]++;
		}
	}
}
struct Ans { int x, y, z; };
vector<Ans> ans;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back({ b,i });
		G[b].push_back({ a,i });
		c[i] = a; s[a]++;
	}
	rep(i, n) {
		if (used[i])continue;
		maketree(i);
		update(i, i, -1);
	}

	rep(i, n) {
		vector<int> nex;
		rep(j, G[i].size()) {
			if (c[G[i][j].id] == i)nex.push_back(G[i][j].to);
		}
		rep(j, nex.size() / 2) {
			ans.push_back({ nex[2 * j] + 1,i + 1,nex[2 * j + 1] + 1 });
		}
	}
	cout << ans.size() << endl;
	rep(i, ans.size()) {
		cout << ans[i].x << " " << ans[i].y << " " << ans[i].z << endl;
	}
	return 0;
}