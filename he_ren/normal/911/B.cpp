#include<cstdio>

inline int min(int a,int b){ return a<b? a: b;}
inline int max(int a,int b){ return a>b? a: b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}

int main(void)
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	
	int ans=0;
	for(int i=1; i<n; ++i)
		if(a>=i && b>=n-i)
			chk_max(ans, min(a/i, b/(n-i)));
	printf("%d",ans);
	return 0;
}