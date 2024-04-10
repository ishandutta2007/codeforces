#include<cstdio>
#define lli long long int
lli n,p,d,w,x,y,g;
int main()
{
	scanf("%lld%lld%lld%lld",&n,&p,&w,&d);
	for(lli y=0,x;y<w;++y)
	{
		if((p-d*y)%w==0) x=(p-d*y)/w;
		if(x>=0&&x+y<=n) return 0&printf("%lld %lld %lld",x,y,n-x-y);
	}
	return 0&printf("-1");
}