#include<cstdio>
const int MAXN = 2e3 + 5;

inline void swap(char &a,char &b){ char t=a; a=b; b=t;}

char s[MAXN],t[MAXN];

struct Oper
{
	int l,r;
}ans[MAXN];

void solve(void)
{
	int n,m;
	scanf("%d%d%s",&n,&m,s+1);
	
	for(int i=1; i<=m-1; ++i) t[i<<1]=')', t[(i<<1)-1]='(';
	for(int i=(m<<1)-1,j=n; j>i; ++i,--j)
		t[i]='(', t[j]=')';
	
	int cnt=0;
	for(int i=1; i<=n; ++i) if(s[i]!=t[i])
		for(int j=i+1; j<=n; ++j)
			if(s[j]!=t[j] && s[j]!=s[i])
			{
				swap(s[i],s[j]);
				ans[++cnt]=(Oper){i,j};
				if(i+1<j-1) ans[++cnt]=(Oper){i+1,j-1};
				break;
			}
	
	printf("%d\n",cnt);
	for(int i=1; i<=cnt; ++i) printf("%d %d\n",ans[i].l,ans[i].r);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}