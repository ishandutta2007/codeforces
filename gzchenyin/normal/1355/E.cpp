#include<cstdio>
#include<algorithm>
using namespace std;
long long n,a,b,c;
long long t[100005];
long long f(int x)
{
	long long tmp1=0,tmp2=0;
	for(int i=1;i<=n;i++)
	{
		if(t[i]<x) tmp1+=x-t[i];
		if(t[i]>x) tmp2+=t[i]-x;
	}
	if(c<a+b) return c*min(tmp1,tmp2)+a*(tmp1-min(tmp1,tmp2))+b*(tmp2-min(tmp1,tmp2));
	else return a*tmp1+b*tmp2;
}
int main()
{
	scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
	long long l=1e9+1,r=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&t[i]);
		l=min(l,t[i]-1);
		r=max(r,t[i]+1);
	}
    while(l<r-1)  
    {  
        long long mid=(l+r)/2;  
        long long mmid=(mid+r)/2;  
        if(f(mid)>f(mmid)) l=mid;  
        else r=mmid;  
//        printf("f(%d)=%d\nf(%d)=%d\n",mid,f(mid),mmid,f(mmid));
//        printf("%lld %lld\n",l,r);
    }  
    long long ans=min(f(l),f(r));
	printf("%lld\n",ans);
}