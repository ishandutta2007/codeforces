#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=1000010;
const LL mo=1000000007;
const LL inv=(mo+1)/3;
int p[N],v[N];
LL phi[N],g[N],f1[N],f2[N],f3[N];
int tt,num;
int main()
{
	phi[1]=1;
	for (int i=2;i<=N;i++)
	{
		if (!v[i]) p[++num]=i,phi[i]=i-1;
		for (int j=1;j<=num&&i*p[j]<=N;j++)
		if (i%p[j]==0)
		{
			v[i*p[j]]=1;
			phi[i*p[j]]=1LL*phi[i]*p[j]%mo;
			break;
		}
		else
		{
			v[i*p[j]]=1;
			phi[i*p[j]]=1LL*phi[i]*(p[j]-1)%mo;
		}
	}
	for (int i=1;i<=N;i++)
	for (int j=i;j<=N;j+=i)
		g[j]=(g[j]+1LL*(j/i)*phi[i])%mo;
	for (int i=1;i<=N;i++) 
	{
		LL f=2LL*i*i*i%mo*inv-2LL*i*i+1LL*i*inv+2*g[i];
		f%=mo;
		f1[i]=(f1[i-1]+f)%mo;
		f2[i]=(f2[i-1]+1LL*f*i)%mo;
		f3[i]=(f3[i-1]+1LL*f*i%mo*i)%mo;
	}
	scanf("%d",&tt);
	while (tt--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (x>y) swap(x,y);
		x++;y++;
		LL ans=(1LL*x*y%mo*f1[x-1]-1LL*(x+y)*f2[x-1]+f3[x-1])%mo;
		ans=(ans+mo)%mo;
		printf("%I64d\n",ans);
	}
	return 0;
}