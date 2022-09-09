#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 10 + 5;
const int d = 52;
const int ALL = (1<<10) + 5;
const int MAXP = d * ALL + 5;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

int n;
vector<int> a[MAXN];
vector<int> pos[MAXN][d];

vector<int> g[MAXP];
int deg[MAXP];
inline void add_edge(int u,int v)
{
	g[u].push_back(v);
	++deg[v];
}

bool is_ok[MAXP];
void dfs_ok(int dep,int x,int mask)
{
	if(dep > n){ is_ok[mask] = 1; return;}
	for(int i=0; i<(int)pos[dep][x].size(); ++i)
		dfs_ok(dep+1, x, mask << 1 | i);
}

void dfs_mask(int dep,int x,int y,int mask1,int mask2)
{
	if(dep > n)
	{
		add_edge(mask1, mask2);
		return;
	}
	
	for(int i=0; i<(int)pos[dep][x].size(); ++i)
		for(int j=0; j<(int)pos[dep][y].size(); ++j) if(pos[dep][x][i] < pos[dep][y][j])
		{
			dfs_mask(dep+1, x, y, mask1 << 1 | i, mask2 << 1 | j);
			break;
		}
}

int f[MAXP], pre[MAXP];

void solve(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		string s;
		cin >> s;
		a[i].resize(s.size());
		for(int j=0; j<(int)s.size(); ++j)
		{
			char c = s[j];
			if(c >= 'a' && c <= 'z') a[i][j] = c - 'a';
			else a[i][j] = c - 'A' + 26;
		}
		
		for(int j=0; j<d; ++j) pos[i][j].clear();
		for(int j=0; j<(int)a[i].size(); ++j)
			pos[i][a[i][j]].push_back(j);
	}
	
	int mxp = d << n;
	for(int i=0; i<mxp; ++i)
		g[i].clear(), deg[i] = 0;
	
	memset(is_ok, 0, sizeof(is_ok));
	for(int i=0; i<d; ++i)
		dfs_ok(1, i, i);
	
	for(int i=0; i<d; ++i)
		for(int j=0; j<d; ++j)
			dfs_mask(1, i, j, i, j);
	
	memset(f, 0, sizeof(f));
	memset(pre, -1, sizeof(pre));
	for(int i=0; i<mxp; ++i)
		if(!is_ok[i]) deg[i] = -1;
	
	queue<int> q;
	for(int i=0; i<mxp; ++i)
		if(deg[i] == 0)
		{
			f[i] = 1; pre[i] = -1;
			q.push(i);
		}
	
	int ans = 0, ansu = -1;
	while(q.size())
	{
		int u = q.front(); q.pop();
		if(ans < f[u])
		{
			ans = f[u];
			ansu = u;
		}
		for(int v: g[u])
		{
			if(f[v] < f[u] + 1)
			{
				f[v] = f[u] + 1;
				pre[v] = u;
			}
			if(--deg[v] == 0) q.push(v);
		}
	}
	
	string anss;
	for(int u=ansu; u!=-1; u=pre[u])
	{
		int c = u>>n;
		if(c < 26) anss += (char)(c + 'a');
		else anss += (char)(c - 26 + 'A');
	}
	reverse(anss.begin(), anss.end());
	
	cout << ans << "\n" << anss << endl;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}