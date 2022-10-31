#include<cstdio>
#include<iostream>
using namespace std;
const int N=1000010,p=1000000007,INV=250000002,INV2=500000004;
int n,ans;
int a[N],v[N],fact[N];
int bit[N];
void C(int i) { for (;i<=n;i+=i&-i) bit[i]++;}
int  Q(int i) { int res=0;for (;i;i-=i&-i) res+=bit[i];return res;}
int main()
{
	scanf("%d",&n);
	ans=0;
	int now=0;
	fact[0]=1;
	for (int i=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
/*		for (int j=1;j<a[i];j++)
		if (!v[j])
		{
			ans=(ans+1LL*fact[n-i]*(1LL*(n-i)%p*(n-i-1)%p*INV%p+now)%p)%p;
			now++;
		}
	//	v[a[i]]=1;
*/		
		int tmp=Q(a[i]);tmp=a[i]-1-tmp;
		ans=(ans+1LL*fact[n-i]*(n-i)%p*(n-i-1)%p*INV%p*tmp)%p;
		ans=(ans+1LL*fact[n-i]*(now+now+tmp-1)%p*tmp%p*INV2)%p;
		C(a[i]);now=(now+tmp)%p;
	}
	ans=(ans+now)%p;
	printf("%d\n",ans);
	return 0;
}