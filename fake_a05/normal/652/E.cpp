#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int> 
#define ii pair<int, int> 
#define fi first
#define se second
#define eb push_back
#define all(x) begin(x), end(x)

#define rand rng
#define sp ' '
#define endl '\n'

const int maxN = 3e5 + 5;

int N, M;
int S, D;
vector<ii> G[maxN];
int par[maxN];
bool toD[maxN];
bool pe[maxN];
bool can;
int low[maxN];
int dis[maxN];
int root[maxN]; // bi cc it belongs to

stack<int> st;
int cnter;
void dfs(int u)
{
	low [u] = dis[u] = ++cnter;
	if(u == D) toD[u] = 1;
	st.push(u);
	for(ii v: G[u])
	{
		if(v.fi == par[u]) continue;
		if(!low[v.fi])
		{
			par[v.fi] = u;
			dfs(v.fi);
			low[u] = min(low[u], low[v.fi]);
			toD[u] |= toD[v.fi];
		}
		else 
		{
			low[u] = min(low[u], dis[v.fi]);
		}
	}
	if(low[u] != dis[u]) return;
	int top;
	vi bi;
	do
	{
		top = st.top();		
		bi.eb(top);
		root[top] = u;
		st.pop();
	} while(top != u);
	if(toD[u])
	{
		for(int t: bi)
		{
			for(ii v: G[t])
			{
				if(v.fi == par[t]) can |= v.se;
				else if(root[v.fi] == u) can |= v.se;
			}
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	loop(i, 1, M)
	{
		int u, v, x;
		cin >> u >> v >> x;
		G[u].eb({v, x});
		G[v].eb({u, x});
//		assert(v != u);
	}
	cin >> S >> D;
	par[S] = S;
	dfs(S);
//	assert(st.empty());
	if(can) cout << "YES\n";
	else cout << "NO\n";
}