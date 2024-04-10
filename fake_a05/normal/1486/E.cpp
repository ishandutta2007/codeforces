#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int> 
#define ii pair<int, int> 
#define eb push_back
#define all(x) begin(x), end(x)
#define fi first
#define se second

#define rand rng
//#define endl '\n'
#define sp ' '


#define int long long

const int maxN = 1e5 + 5, maxW = 3005, mod = 998244353, inf = LLONG_MAX / 1000ll;
#define iii pair<int, ii>
int d[maxN][105];
int N, M; 
vector<ii> g[maxN];
signed main()
{
//	freopen("ball.inp", "r", stdin);
//	freopen("ball.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
		cin >> N >> M;
	loop(i, 1, N)
	{
		loop(c, 0, 100) d[i][c] = inf;
	}
	loop(i, 1, M) 
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u].eb({v, w});
		g[v].eb({u, w});
	}
	d[1][0] = 0;
	priority_queue<iii, vector<iii>, greater<iii> > q;
	q.push({0, {1, 0}});
	while(!q.empty())
	{
		int dis = q.top().fi,u = q.top().se.fi, c = q.top().se.se;
		q.pop();
		if(dis != d[u][c]) continue;
		if(!c)
		{
			for(ii e: g[u])
			{
				int v = e.fi, w = e.se;
				if(d[v][w] > d[u][c] + w * w) 
				{
					d[v][w] = d[u][c] + w * w;
					q.push({d[v][w], {v, w}});
				}
			}
		}
		else
		{
			for(ii e: g[u])
			{
				int v = e.fi, w = e.se;
				if(d[v][0] > d[u][c] + 2 * c * w + w * w)
				{
					d[v][0] = d[u][c] + 2 * c * w + w * w;
					q.push({d[v][0], {v, 0}});
				}
			}
		}
	}
	loop(i, 1, N) cout << (d[i][0] == inf? -1: d[i][0]) << endl;
}