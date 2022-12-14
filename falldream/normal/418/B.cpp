#include<algorithm>
#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,b;
ll f[1<<20];
struct data{int x,k,s;}s[105];
bool cmp(const data&a,const data&b){return a.k>b.k;}
inline void R(ll&a,ll b){b<a?a=b:0;}
int main()
{
	n=read();m=read();b=read();
	for(int i=0;i<1<<m;++i) f[i]=2e18;
	for(int i=1;i<=n;++i)
	{
		s[i].x=read();s[i].k=read();int k=read();
		for(int j=1;j<=k;++j) s[i].s|=1<<(read()-1);	
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<1<<m;++j) R(f[j|s[i].s],f[j]+s[i].x);
		f[s[i].s]=min(f[s[i].s],s[i].x+1LL*s[i].k*b);	
	}
	printf("%lld\n",f[(1<<m)-1]<2e18?f[(1<<m)-1]:-1);
	return 0;
}