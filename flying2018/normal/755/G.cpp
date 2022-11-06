#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define mod 998244353
#define G 3
#define Gi 332748118
#define N 500010
#define ll long long
using namespace std;
ll ksm(ll a,ll b=mod-2)
{
	ll ans=1;
	for(;b;b>>=1)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
int rev[N];
int get_rev(int n)
{
	int lim=1,l=0;
	while(lim<n<<1) lim=lim<<1,l++;
	for(int i=0;i<lim;i++)
	rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
	return lim;
}
void ntt(ll f[],int lim,int opt)
{
	for(int i=0;i<lim;i++)
	if(i<rev[i]) swap(f[i],f[rev[i]]);
	for(int mid=1;mid<lim;mid<<=1)
	{
		ll rot=ksm(opt==1?G:Gi,(mod-1)/(mid*2));
		for(int i=0;i<lim;i+=mid<<1)
		{
			ll o=1;
			for(int j=0;j<mid;j++,o=o*rot%mod)
			{
				ll x=f[i+j],y=f[i+j+mid]*o%mod;
				f[i+j]=(x+y)%mod;
				f[i+j+mid]=(x-y+mod)%mod;
			}
		}
	}
	if(opt==-1)
	{
		ll iv=ksm(lim);
		for(int i=0;i<lim;i++) f[i]=f[i]*iv%mod;
	}
}
ll swp[3][N],tmp[3][N],f[3][N];
int n,k;
void to_mul()
{
	int lim=get_rev(k);
	for(int i=0;i<=2;i++)
		ntt(f[i],lim,1);
	for(int i=0;i<=2;i++)
		for(int j=0;j<lim*2;j++) tmp[i][j]=swp[i][j]=0;
	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<lim;j++) tmp[i][j]=f[i/2][j]*f[i-i/2][j]%mod;
		for(int j=0;j<lim;j++) swp[i][j]=f[i/2+1][j]*f[i-i/2+1][j]%mod;
	}
	for(int i=0;i<=2;i++)
	{
		ntt(tmp[i],lim,-1);
		ntt(swp[i],lim,-1);
		for(int j=1;j<lim;j++) tmp[i][j]=(tmp[i][j]+swp[i][j-1])%mod;
	}
	for(int i=0;i<=2;i++)
	{
		memcpy(f[i],tmp[i],sizeof(tmp[i]));
		for(int j=k;j<lim;j++) f[i][j]=0;
	}
}
void to_next()
{
    memcpy(f[2],f[1],sizeof(f[2]));
    memcpy(f[1],f[0],sizeof(f[1]));
	for(int i=0;i<k;i++)
	if(i) f[0][i]=(f[1][i]+f[1][i-1]+f[2][i-1])%mod;
	else f[0][i]=f[1][i];
}
int main()
{
	scanf("%d%d",&n,&k);
	k++;
	f[0][0]=1;
	int u=0;
	for(int i=1<<30;i;i>>=1)
	{
        if(u) to_mul(),u<<=1;
		if(n&i) to_next(),u++;
	}
	for(int i=1;i<k;i++) printf("%lld ",f[0][i]);
	return 0;
}