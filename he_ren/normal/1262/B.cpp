#include<cstdio>
const int MAXN = 1e5 + 5;

inline int max(int a,int b){ return a>b? a: b;}

int p[MAXN],q[MAXN],pre[MAXN];
bool t[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&q[i]);
	
	for(int i=1; i<=n; ++i) t[i]=0;
	for(int i=1; i<=n; ++i)
	{
		if(q[i]==q[i-1]) p[i]=0;
		else p[i]=q[i], t[q[i]]=1;
	}
	
	for(int i=1,j=1; i<=n; ++i)
		if(!p[i])
		{
			while(t[j]) ++j;
			p[i]=j;
			t[j]=1;
		}
	
	pre[1]=p[1];
	for(int i=2; i<=n; ++i)
		pre[i]=max(p[i],pre[i-1]);
	
	for(int i=1; i<=n; ++i)
		if(q[i]!=pre[i]){ printf("-1\n"); return;}
	for(int i=1; i<=n; ++i) printf("%d ",p[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}