#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
const int xx=1e5+5;
int n;
char s[xx][2];
const int mod=998244353;
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
ll C(ll n,ll m)
{
	ll ans=1,res=1;
	for(int i=1;i<=m;i++)
		ans*=(n-i+1),ans%=mod;
	for(int i=1;i<=m;i++)res*=i,res%=mod;
	ans*=ksm(res,mod-2);
	return ans%mod;
}
signed main(){
	n=read();
	int tt1=0,tt2=0,tt3=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]);
		for(int j=0;j<=1;j++)
			tt1+=(s[i][j]=='W'),tt2+=(s[i][j]=='B'),tt3+=(s[i][j]=='?');
	}
	if(max(tt1,tt2)-min(tt1,tt2)>tt3)
	{
		puts("0");
		exit(0);
	}
	ll sum=C(tt3,(tt3-(max(tt1,tt2)-min(tt1,tt2)))/2);
	ll re=1;
	for(int i=1;i<=n;i++)
	{
		if(s[i][0]=='?'&&s[i][1]=='?')re*=2,re%=mod;
		if(s[i][0]=='W'&&s[i][1]=='W')re=0;
		if(s[i][0]=='B'&&s[i][1]=='B')re=0;
	}
	sum+=mod-re;
	re=1;
	for(int i=1;i<=n;i++)
	{
		//BW 
		if(s[i][0]=='W')re=0;
		if(s[i][1]=='B')re=0;
	}
	sum+=re;
	re=1;
	for(int i=1;i<=n;i++)
	{
		//WB 
		if(s[i][0]=='B')re=0;
		if(s[i][1]=='W')re=0;
	}
	sum+=re;
	sum%=mod;
	cout<<sum<<"\n";
	pc('1',1);
	return 0;
}