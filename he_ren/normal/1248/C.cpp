#include<cstdio>
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;

inline void add(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

int f[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	f[0]=f[1]=1;
	for(int i=2; i<=n || i<=m; ++i)
		add(f[i], f[i-1]+f[i-2]);
	
	int ans = 0;
	add(ans, f[n]+f[m]);
	--ans;
	if(ans<0) ans+=mod;
	
	add(ans,ans);
	printf("%d",ans);
	return 0;
}