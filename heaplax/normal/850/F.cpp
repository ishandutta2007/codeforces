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
#define N 2501
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
const int mod=1000000007;
int n,sum,a[N],f[100001];
int mi(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	re(n);
	for(int i=1;i<=n;++i)re(a[i]),sum+=a[i];
	f[1]=(sum-1ll)*(sum-1)%mod*mi(sum,mod-2)%mod;
	f[2]=(2*f[1]-1)%mod;
	for(int i=3;i<=100000;++i)
		f[i]=(2ll*f[i-1]-f[i-2]-(sum-1ll)*mi(sum-i+1,mod-2))%mod;
	int ans=0;
	// cerr<<f[1]<<" "<<f[2]<<" "<<f[3]<<endl;
	for(int i=1;i<=n;++i)
		ans=(ans+f[a[i]])%mod;
	ans=(ans+mod)%mod;
	printf("%d\n",ans);
}
/*
f(i) = 2f(i-1)-f(i-2)-(s-1)/(s-i-1)
*/