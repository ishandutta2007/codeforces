#include<bits/stdc++.h>
#define ll long long 
//#define int long long 
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;};return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;else if(c==EOF)assert(0);
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=2e6+5,mod=1e9+7;
namespace tb
{
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int n,id[(int)1e6+5];
bool check()
{
	int cr=1;
//	if(id[2]!=2||id[4]!=4||(n>=8&&id[8]!=8))return 0;
//	if(id[3]!=3||id[9]!=9)return 0;
//	if(id[2]!=2||id[4]!=4||(n>=8&&id[8]!=8))return 0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if((gcd(i,j)==1)^(gcd(id[i],id[j])==1))return 0;
	return 1;
}
// 
void table()
{
//	int ct=0;
//	for(int i=1;i<=1e4;i++)
//		for(int j=1;j<=1e4;j++)
//			if(gcd(i,j)==1)ct++;
//	cout<<ct<<"\n";
	n=read();
	ll re=1;
	for(int i=1;i<=n;i++)id[i]=i,re*=i;
	while(re--)
	{
		if(check())
		{
			for(int i=1;i<=n;i++)cout<<id[i]<<" ";
			puts("");
		}
		next_permutation(id+1,id+n+1);
	}
}
	
}
//1=11 
int n;
int mn[xx],mx[xx],Mn[xx],prim[xx],cnt;
void pre()
{
	mn[1]=1,mx[1]=1;
	for(int i=2;i<xx;i++)
	{
		if(!mn[i])mn[i]=mx[i]=Mn[i]=i,prim[++cnt]=i;
		for(int j=1;j<=cnt;j++)
		{
			if(prim[j]*i>=xx)break;
			mn[i*prim[j]]=prim[j];
			mx[i*prim[j]]=max(prim[j],mx[i]);
			Mn[i*prim[j]]=(mn[i]==prim[j])?Mn[i]:Mn[i]*prim[j];
			if(i%prim[j]==0)break;
		}
	}
}
int bel[xx],ty[xx],Ct[xx],a[xx],ct[xx];
int jiec[xx],rd[xx];
signed main(){
//	tb::table();
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=1ll*jiec[i-1]*i%mod;
	pre();
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)bel[i]=n/i;
	bel[1]=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=0)
		{
//			cerr<<mx[i]<<" "<<mx[a[i]]<<"@\n";
			if(bel[mx[i]]!=bel[mx[a[i]]])puts("0"),exit(0);
//			if(mx[i]==mx[a[i]])
			if(ty[mx[i]]&&ty[mx[i]]!=mx[a[i]])puts("0"),exit(0);
			if(!ty[mx[i]])rd[mx[a[i]]]++;
			ty[mx[i]]=mx[a[i]];
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++)if(rd[i]>1)puts("0"),exit(0);
	for(int i=1;i<=n;i++)
		if(!a[i])Ct[Mn[i]]++;
	for(int i=1;i<=n;i++)
		ans=1ll*ans*jiec[Ct[i]]%mod;
	for(int i=1;i<=n;i++)if(mn[i]==i)if(!ty[i])ct[bel[i]]++;
//	for(int i=1;i<=n;i++)cerr<<ct[i]<<"@\n";
	for(int i=1;i<=n;i++)
		ans=1ll*ans*jiec[ct[i]]%mod;
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}