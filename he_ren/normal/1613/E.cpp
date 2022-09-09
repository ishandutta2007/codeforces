#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXP = 1e6 + 5;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

int n,m,pcnt;

inline bool isin(int x,int y){ return 0 <= x && x < n && 0 <= y && y < m;}
inline int encode(int x,int y){ return isin(x,y)? x * m + y: -1;}
inline void decode(int u,int &x,int &y){ x = u / m; y = u % m;}
inline int walk(int u,int k)
{
	return u == -1? -1: encode(u / m + dx[k], u % m + dy[k]);
}

char s[MAXP];
vector<int> g[MAXP];
int deg[MAXP];

void solve(void)
{
	scanf("%d%d",&n,&m);
	pcnt = n * m;
	for(int i=0; i<pcnt; i+=m) scanf("%s",s+i);
	
	for(int i=0; i<pcnt; ++i) g[i].clear(), deg[i] = 0;
	for(int i=0; i<pcnt; ++i) if(s[i] != '#')
		for(int k=0; k<4; ++k)
		{
			int j = walk(i,k);
			if(j != -1 && s[j] != '#')
				g[i].push_back(j), ++deg[i];
		}
	
	static bool vis[MAXP];
	memset(vis, 0, pcnt);
	queue<int> q;
	
	int beg = find(s,s+pcnt,'L') - s;
	vis[beg] = 1; q.push(beg);
	while(q.size())
	{
		int u = q.front(); q.pop();
		for(int v: g[u]) if(!vis[v])
		{
			--deg[v];
			if(deg[v] <= 1)
				vis[v] = 1, q.push(v);
		}
	}
	
	for(int i=0; i<n; ++i, putchar('\n'))
		for(int j=0; j<m; ++j)
		{
			int u = encode(i,j);
			if(s[u] != '.') putchar(s[u]);
			else putchar(vis[u]? '+': '.');
		}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}