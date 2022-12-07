#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 1<<20
#define LL long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;
}
using namespace std;
const int mod=1000000007,inv2=(mod+1)/2;
int n,m,ans,bit[N],a[N];
char s[N];
int add(int a)
{
	return a<mod?a:a-mod;
}
int dec(int a)
{
	return a<0?a+mod:a;
}
void fwt(int *x,int n,int f)
{
	for(int i=1;i<n;i<<=1)
		for(int j=0;j<n;j+=i<<1)
			for(int k=0;k<i;++k)
			{
				int l=x[j+k],r=x[i+j+k];
				x[j+k]=add(l+r);x[i+j+k]=dec(l-r);
				if(!~f)
					x[j+k]=1ll*x[j+k]*inv2%mod,
					x[i+j+k]=1ll*x[i+j+k]*inv2%mod;
			}
}
int main()
{
	re(n);m=1<<n;
	scanf("%s",s);
	for(int i=0;i<m;++i)
		a[i]=s[i]-'0';
	fwt(a,m,1);
	for(int i=0;i<m;++i)
		a[i]=1ll*a[i]*a[i]%mod;
	fwt(a,m,-1);
	bit[0]=1<<n;
	for(int i=1;i<m;++i)
	{
		bit[i]=bit[i>>1];
		if(i&1)bit[i]=1ll*bit[i]*inv2%mod;
	}
	for(int i=0;i<m;++i)
		ans=(ans+1ll*a[i]*bit[i])%mod;
	printf("%d\n",3ll*ans%mod);
}