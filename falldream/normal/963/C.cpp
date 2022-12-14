#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 200000 
#define ll long long
#define mod1 998244353
#define mod2 1000000007
using namespace std;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,num1,num2;
ll *a[MN+5],x[MN+5],y[MN+5],Lx[MN+5],Ly[MN+5],w[MN+5],rk[MN+5],g=0;
bool cmp1(int x,int y){return a[x][1]<a[y][1];}
bool cmp2(int x,int y){return a[1][x]<a[1][y];}
bool Same(ll x,ll y,ll X,ll Y)
{
	if(1LL*(x%mod1)*(Y%mod1)%mod1!=1LL*(y%mod1)*(X%mod1)%mod1) return false;
	if(1LL*(x%mod2)*(Y%mod2)%mod2!=1LL*(y%mod2)*(X%mod2)%mod2) return false;
	return true;
}
int Solve(ll s)
{
	int res=1;
	for(int i=2;i<=1000000;++i) if(s%i==0)
	{
		int num=1;
		while(s%i==0) s/=i,++num;
		res*=num;
	}
	if(s>1) res*=2;
	return res;
}
inline ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) x[i]=Lx[i]=read(),y[i]=Ly[i]=read(),w[i]=read(),g=gcd(w[i],g);
	sort(Lx+1,Lx+n+1);num1=unique(Lx+1,Lx+n+1)-Lx-1;
	sort(Ly+1,Ly+n+1);num2=unique(Ly+1,Ly+n+1)-Ly-1;
	if(1LL*num1*num2!=n) return 0*puts("0");
	for(int i=0;i<=num1;++i) a[i]=new ll[num2+5];
	for(int i=1;i<=n;++i)
		a[lower_bound(Lx+1,Lx+num1+1,x[i])-Lx][lower_bound(Ly+1,Ly+num2+1,y[i])-Ly]=w[i];
	for(int i=1;i<=num1;++i) rk[i]=i;
	sort(rk+1,rk+num1+1,cmp1);
	for(int j=2;j<=num2;++j)
		for(int i=2;i<=num1;++i)
			if(!Same(a[rk[i]][1],a[rk[i-1]][1],a[rk[i]][j],a[rk[i-1]][j])) return 0*puts("0");	
	for(int i=1;i<=num2;++i) rk[i]=i;
	sort(rk+1,rk+num2+1,cmp2);
	for(int i=2;i<=num1;++i)
		for(int j=2;j<=num2;++j)
			if(!Same(a[1][rk[j]],a[1][rk[j-1]],a[i][rk[j]],a[i][rk[j-1]])) return 0*puts("0");
	printf("%d\n",Solve(g));
	return 0;
}