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
#define N 100001
#define LL long long
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
int n,m,q,w[N],phi[31];
int ph(int x)
{
	int res=x;
	for(int i=2;i*i<=x;++i)
		if(x%i==0)
		{
			while(x%i==0)x/=i;
			res/=i;
			res*=i-1;
		}
	if(x>1)res/=x,res*=x-1;
	return res;
}
int gg(LL x,int mod)
{
	return x<mod?x:x%mod+mod;
}
int mi(int a,int b,int mod)
{
	int res=1;
	while(b)
	{
		if(b&1)res=gg(1ll*res*a,mod);
		a=gg(1ll*a*a,mod);
		b>>=1;
	}
	return res;
}
int solve(int l,int r,int step)
{
	if(l==r || phi[step]==1)return gg(w[l],phi[step]);
	else return mi(w[l],solve(l+1,r,step+1),phi[step]);
}
int main()
{
	re(n),re(m);
	for(int i=1;i<=n;++i)re(w[i]);
	phi[0]=m;
	for(int i=1;i<=30;++i)
		phi[i]=ph(phi[i-1]);
	re(q);
	for(int l,r;q--;)
	{
		re(l),re(r);
		printf("%d\n",solve(l,r,0)%m);
	}
}