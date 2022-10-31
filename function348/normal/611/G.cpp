#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=1000010,mo=1000000007;
struct point {LL x,y;};
int n;
point a[N],p[N];
LL sum1[N],sum2[N];
LL ans;
LL operator * (point a,point b) { return a.y*b.x-a.x*b.y;}
point operator + (point a,point b) { return (point){a.x+b.x,a.y+b.y};}
point operator - (point a,point b) { return (point){a.x-b.x,a.y-b.y};}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld%lld",&a[i].x,&a[i].y);
	for (int i=1;i<=n;i++) a[i+n]=a[i];
	LL S=0,now=0;
	for (int i=1;i<=n;i++) S+=a[i]*a[i+1];
	for (int i=1;i<=n*2;i++) sum1[i]=(sum1[i-1]+a[i-1]*a[i])%mo;
	for (int i=1;i<=n*2;i++) sum2[i]=(sum2[i-1]+sum1[i])%mo;
	for (int i=1;i<=n*2;i++) { p[i]=p[i-1]+a[i];p[i].x%=mo;p[i].y%=mo;}
	for (int i=1,j=1;i<=n;i++)
	{
		while (now+a[j]*a[j+1]+a[j+1]*a[i]<=S/2) 
		{
			now+=a[j]*a[j+1],j++;
		}
		LL tmp=sum2[j]-sum2[i]-1LL*(j-i)*sum1[i]+(p[j]-p[i])*a[i];
		tmp%=mo;ans=(ans+tmp)%mo;
		if ((now+a[j]*a[i])*2==S&&j>n) ans-=(S/2)%mo;
		
		now-=a[i]*a[i+1];
	}
	ans=-ans*2;
	ans=ans+1LL*S%mo*n%mo*(n-3)%mo*((mo+1)/2)%mo;
	ans%=mo;ans=(ans+mo)%mo;
	cout<<ans<<endl;
	return 0;
}