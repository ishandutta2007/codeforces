#include<cstdio>
#include<algorithm>
const int N=200005;
int a[N];
inline int max(int a,int b){return a>b?a:b;}
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) ans=max(ans,std::upper_bound(a+1,a+n+1,a[i]+5)-a-i);
	printf("%d\n",ans);
	return 0;
}