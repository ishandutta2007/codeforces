#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1.5e5 + 5;
const int inf = 0x3f3f3f3f;

int n[6], a[6][MAXN];
vector<int> g[6][MAXN];
int f[6][MAXN];

int main(void)
{
	for(int i=1; i<=4; ++i) scanf("%d",&n[i]);
	for(int i=1; i<=4; ++i)
		for(int j=1; j<=n[i]; ++j)
			scanf("%d",&a[i][j]);
	for(int k=1; k<=3; ++k)
	{
		int m;
		scanf("%d",&m);
		while(m--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[k][u].push_back(v);
		}
	}
	
	for(int i=1; i<=n[4]; ++i) f[4][i] = a[4][i];
	for(int k=3; k>=1; --k)
	{
		static pii t[MAXN];
		int nn = n[k+1];
		for(int i=1; i<=nn; ++i) t[i] = make_pair(f[k+1][i], i);
		sort(t+1,t+nn+1);
		
		for(int i=1; i<=n[k]; ++i)
		{
			set<int> fob;
			for(int j=0; j<(int)g[k][i].size(); ++j)
				fob.insert(g[k][i][j]);
			
			f[k][i] = inf;
			for(int j=1; j<=nn; ++j) if(!fob.count(t[j].second))
			{
				f[k][i] = t[j].first + a[k][i];
				break;
			}
		}
	}
	
	int ans = inf;
	for(int i=1; i<=n[1]; ++i)
		ans = min(ans, f[1][i]);
	
	if(ans == inf) printf("-1");
	else printf("%d",ans);
	return 0;
}