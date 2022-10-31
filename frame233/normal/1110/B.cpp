#include<cstdio>
#include<algorithm>
int a[100005],d[100005];
inline bool cmp(int a,int b){return a>b;}
int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	long long s=a[n]-a[1]+1;
	for(int i=1;i<n;++i) d[i]=a[i+1]-a[i]-1;
	std::sort(d+1,d+n,cmp);
	for(int i=1;i<k;++i) s-=(long long)(d[i]);
	printf("%lld\n",s);
	return 0;
}