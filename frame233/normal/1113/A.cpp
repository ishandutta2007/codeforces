#include<cstdio>
#include<algorithm>

int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
inline int abs(int a){return a>0?a:-a;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

int main()
{
	int n,v;
	scanf("%d %d",&n,&v);
	if(v>=n) return printf("%d\n",n-1),0;
	int ans=v;
	for(int i=2;i<=n-v;++i) ans+=i;
	//1 v
	//2 2
	//3 3
	//n-v -> n
	printf("%d\n",ans);
	return 0;
}