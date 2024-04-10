#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e2 + 5;
const int mod = 998244353;

int n;
int a[MAXN * 2][MAXN];

vector<int> g[MAXN * 2];
bool del[MAXN * 2];

inline bool chk_eq(int i,int j)
{
	for(int k=1; k<=n; ++k)
		if(a[i][k] == a[j][k]) return 1;
	return 0;
}

vector<int> res;
inline void upd_res(int u)
{
	res.push_back(u);
	del[u] = 1;
	for(int i=0; i<(int)g[u].size(); ++i)
		del[g[u][i]] = 1;
}

void solve(void)
{
	scanf("%d",&n);
	int nn = 2 * n;
	for(int i=1; i<=nn; ++i)
		for(int j=1; j<=n; ++j)
			scanf("%d",&a[i][j]);
	
	memset(del, 0, nn+1);
	for(int i=1; i<=nn; ++i)
	{
		g[i].clear();
		for(int j=1; j<=nn; ++j)
			if(j != i && chk_eq(i, j))
				g[i].push_back(j);
	}
	
	int ans = 1;
	res.clear();
	while(1)
	{
		int ok = 0;
		for(int j=1; j<=n; ++j)
		{
			static int tag[MAXN];
			memset(tag, 0, (n + 1) << 2);
			for(int i=1; i<=nn; ++i) if(!del[i])
			{
				if(tag[a[i][j]]) tag[a[i][j]] = -1;
				else tag[a[i][j]] = i;
			}
			
			for(int i=1; i<=n; ++i)
				if(tag[i] && tag[i] != -1)
				{
					upd_res(tag[i]);
					ok = 1;
					break;
				}
		}
		
		if(ok) continue;
		
		for(int u=1; u<=nn; ++u) if(!del[u])
		{
			upd_res(u);
			ok = 1;
			ans = ans * 2 %mod;
			break;
		}
		if(!ok) break;
	}
	
	printf("%d\n",ans);
	for(int i=0; i<(int)res.size(); ++i)
		printf("%d ",res[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}