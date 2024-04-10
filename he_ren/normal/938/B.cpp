#include<cstdio>
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int fp = 1e6;

inline int max(int a,int b){ return a>b? a: b;}
inline void chk_min(int &a,int b){ if(a>b) a=b;}

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	a[0]=1; a[n+1]=fp;
	
	int ans=inf;
	for(int i=0; i<=n; ++i)
		chk_min(ans, max(a[i]-1, fp-a[i+1]) );
	printf("%d",ans);
	return 0;
}