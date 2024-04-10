#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXM = (1<<14) + 5;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

int fa[MAXM * 2];
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
inline void connect(int u,int v)
{
	u = find(u); v = find(v);
	if(u > v) fa[u] = v;
	else fa[v] = u;
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	int ans = 0;
	static int a[MAXM], lst[MAXM];
	for(int k=1; k<=n; ++k)
	{
		static char s[MAXM];
		memcpy(lst, a, (m+1)<<2);
		
		scanf("%s",s+1);
		for(int i=1,j=1; i<=(m>>2); ++i, j+=4)
		{
			int x = s[i] >= '0' && s[i] <= '9'? s[i] - '0': s[i] - 'A' + 10;
			a[j+0] = bdig(x, 3); a[j+1] = bdig(x, 2);
			a[j+2] = bdig(x, 1); a[j+3] = bdig(x, 0);
		}
		
		for(int i=1; i<=m; ++i)
			if(fa[i]) fa[i] += m;
		memcpy(fa+m+1, fa+1, (m+1)<<2);
		
		for(int i=1; i<=m; ++i)
		{
			if(a[i])
			{
				fa[i] = a[i-1]? find(i-1): i;
				if(lst[i]) connect(i, m+i);
			}
			else fa[i] = 0;
		}
		
		for(int i=m+1; i<=m+m; ++i)
			if(fa[i] == i) ++ans;
	}
	
	for(int i=1; i<=m; ++i)
		if(fa[i] == i) ++ans;
	
	printf("%d",ans);
	return 0;
}