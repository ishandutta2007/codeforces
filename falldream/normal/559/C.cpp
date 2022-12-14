#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 200000
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
pair<int,int> s[2007];
int n,r,c,p[MN+5],inv[MN+5],f[2007];
inline int C(int n,int m){return 1LL*p[n]*inv[m]%mod*inv[n-m]%mod;} 
int main()
{
	p[0]=p[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=MN;++i) p[i]=1LL*p[i-1]*i%mod,inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=MN;++i) inv[i]=1LL*inv[i]*inv[i-1]%mod;
	r=read();c=read();n=read();
	for(int i=1;i<=n;++i) s[i].first=read(),s[i].second=read();
	s[++n]=make_pair(1,1);s[++n]=make_pair(r,c);
	sort(s+1,s+n+1);f[1]=mod-1;n=unique(s+1,s+n+1)-s-1;
	for(int i=2,x,y;i<=n;++i)for(int j=1;j<i;++j)
		if((x=s[i].first-s[j].first)>=0&&(y=s[i].second-s[j].second)>=0)
			f[i]=(f[i]-1LL*C(x+y,y)*f[j]%mod+mod)%mod; 
	printf("%d\n",f[n]);
	return 0;
}