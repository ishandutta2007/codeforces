#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 30
#define mod 998244353
#define ms(x) memset(x,0,sizeof(x))
#define OP(x) ((x&1)?mod-1:1)
using namespace std;
const int Inv=616898040,N=1000000;
int n,C[MN+5][MN+5],num[MN+5],inv[MN+5],all[MN+5],sum[MN+5],s[MN+5],A[MN+5][30005];
struct Poly
{
	int s[33],len;
	Poly(){}
	Poly(int x,int y){ms(s);len=2;s[1]=x;s[0]=y;}
	Poly operator+(const Poly&y)
	{
		Poly c;ms(c.s);c.len=max(len,y.len);
		for(int i=0;i<c.len;++i) c.s[i]=(s[i]+y.s[i])%mod;
		return c;
	}
	Poly operator-(const Poly&y)
	{
		Poly c;ms(c.s);c.len=max(len,y.len);
		for(int i=0;i<c.len;++i) c.s[i]=(s[i]-y.s[i]+mod)%mod;
		return c;
	}
	Poly Trans()
	{
		Poly c;ms(c.s);c.len=len;
		for(int i=0;i<len;++i) for(int j=0;j<=i;++j) 
			c.s[j]=(c.s[j]+1LL*s[i]*C[i][j]%mod*OP(i-j))%mod;
		return c;
	}
	Poly integral()
	{
		if(!len) return *this;
		Poly c;ms(c.s);c.len=len+1;
		for(int i=0;i<len;++i) c.s[i+1]=(c.s[i+1]+1LL*s[i]*inv[i+1])%mod;
		return c;
	}
	int Calc(int x)
	{
		int res=0;
		for(int i=0,j=1;i<len;++i,j=1LL*j*x%mod) res=(res+1LL*j*s[i])%mod;
		return res;
	}
}a[MN+5][10005];
void CalcInter(int x)
{
	int tot=0;
	all[x]=a[x][num[x]].Calc(1LL*A[x][num[x]]*Inv%mod);
	for(int i=1;i<=num[x];++i)
	{
		a[x][i]=a[x][i].integral();	
		int valR=a[x][i].Calc(1LL*A[x][i]*Inv%mod);
		int valL=a[x][i].Calc(1LL*A[x][i-1]*Inv%mod);
		a[x][i].s[0]=(1LL*a[x][i].s[0]+tot-valL+mod)%mod;
		tot=(1LL*tot+valR-valL+mod)%mod;
	}
	sum[x]=tot;
}
Poly Query(int x,int s)
{
	if(s<=0) return a[n+1][0];
	if(s>A[x][num[x]])
	{
		int now=1LL*A[x][num[x]]*Inv%mod;
		return Poly(all[x],(mod-1LL*now*all[x]%mod+sum[x])%mod);
	}
	int pos=lower_bound(A[x]+1,A[x]+num[x]+1,s)-A[x];
	return a[x][pos];
}
int main()
{
	scanf("%d",&n);inv[0]=inv[1]=1;double S;
	for(int i=1;i<=n;++i) scanf("%lf",&S),s[i]=min(int(S*N+0.5),i*N);
	for(int i=n;--i;) s[i]=min(s[i],s[i+1]); 
	for(int i=2;i<=n+2;++i) s[i]=min(s[i],s[i-1]+N),inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=0;i<=n+1;++i) C[i][0]=1;
	for(int i=1;i<=n+1;++i) for(int j=1;j<=i;++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	num[1]=1;A[1][1]=s[1];a[1][1].len=2;a[1][1].s[1]=1;
	for(int i=2;i<=n;++i)
	{
		A[i][num[i]=1]=N;
		for(int j=1;j<=num[i-1];++j)
			A[i][++num[i]]=A[i-1][j],A[i][++num[i]]=A[i-1][j]+N;
		sort(A[i]+1,A[i]+num[i]+1);
		num[i]=unique(A[i],A[i]+num[i]+1)-A[i]-1;
		while(A[i][num[i]]>=s[i]) --num[i];A[i][++num[i]]=s[i];
		CalcInter(i-1);
		for(int j=1;j<=num[i];++j)
			a[i][j]=Query(i-1,A[i][j])-Query(i-1,A[i][j]-N).Trans();
	}
	printf("%d\n",1LL*a[n][num[n]].Calc(1LL*s[n]*Inv%mod));
	return 0;
}