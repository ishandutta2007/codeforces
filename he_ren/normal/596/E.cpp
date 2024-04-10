#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e2 + 5;
const int MAXM = 2e2 + 5;
const int MAXP = MAXN * MAXM;
const int MAXL = 1e6 + 5;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

int n,m,pcnt;

inline bool is_in(int x,int y){ return 0 <= x && x < n && 0 <= y && y < m;}
inline int encode(int x,int y){ return is_in(x,y)? x * m + y: -1;}
inline void decode(int u,int &x,int &y){ x = u / m; y = u % m;}

int a[MAXP], wx[15], wy[15];
int nxt[MAXP];
vector<int> g[MAXP];

bool vis[MAXP], incir[MAXP];
int cmask[MAXP];

void dfs_vis(int u)
{
	vis[u] = 1;
	for(int v: g[u])
		if(!incir[v]) dfs_vis(v);
}

vector<int> get_cir(int u)
{
	while(!vis[u]) vis[u] = 1, u = nxt[u];
	
	int rt = u;
	vector<int> res;
	do res.push_back(u), u = nxt[u]; while(u != rt);
	
	int mask = 0;
	for(int i: res) incir[i] = 1, mask |= bbit(a[i]);
	for(int i: res) cmask[i] = mask;
	for(int i: res) dfs_vis(i);
	return res;
}

int main(void)
{
	int Q;
	scanf("%d%d%d",&n,&m,&Q);
	pcnt = n * m;
	for(int i=0; i<n; ++i)
	{
		static char s[MAXM];
		scanf("%s",s);
		for(int j=0; j<m; ++j) a[encode(i,j)] = s[j] - '0';
	}
	for(int i=0; i<=9; ++i)
		scanf("%d%d",&wx[i],&wy[i]);
	
	for(int u=0; u<pcnt; ++u)
	{
		int x,y; decode(u,x,y);
		nxt[u] = encode(x + wx[a[u]], y + wy[a[u]]);
		if(nxt[u] == -1) nxt[u] = u;
		g[nxt[u]].push_back(u);
	}
	
	for(int i=0; i<pcnt; ++i) if(!vis[i])
		get_cir(i);
	
	while(Q--)
	{
		static char s[MAXL];
		scanf("%s",s+1);
		int len = strlen(s+1);
		
		static int b[MAXL], suf[MAXL];
		b[len+1] = -1; suf[len+1] = 0;
		for(int i=len; i>=1; --i)
			b[i] = s[i] - '0',
			suf[i] = suf[i+1] | bbit(b[i]);
		
		static int dp[MAXP];
		function<void(int)> dfs_dp = [&] (int u)
		{
			dp[u] = a[u] == b[1];
			for(int v: g[u]) if(!incir[v])
			{
				dfs_dp(v);
				dp[u] = max(dp[u], dp[v] + (a[u] == b[dp[v] + 1]));
			}
		};
		
		bool ok = 0;
		for(int i=0; i<pcnt; ++i) if(incir[i])
		{
			dfs_dp(i);
			int x = cmask[i], y = suf[dp[i] + 1];
			if((x & y) == y)
			{
				ok = 1;
				break;
			}
		}
		
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}