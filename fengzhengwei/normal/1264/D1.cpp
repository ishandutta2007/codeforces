#include<bits/stdc++.h>
#define ll long long 
#define dd double
using namespace std;
char gc(){static char buf[1<<20],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
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
	pc(x%10+'0',0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=1e6+5,mod=998244353;
char s[xx];
ll jiec[xx],ni[xx];
ll C(ll n,ll m){return (m<0||m>n)?0:jiec[n]*ni[m]%mod*ni[n-m]%mod;}
int n,pr[xx],tt,_pr[xx],_sf[xx],sf[xx];
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
int main(){
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
//	for(int i=0;i<=10;i++)cout<<i<<" "<<ni[i]<<"!!\n";
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		_pr[i]=_pr[i-1]+(s[i]=='('),
		pr[i]=pr[i-1]+(s[i]=='?');
	for(int i=n;i>=1;i--)
		sf[i]=sf[i+1]+(s[i]==')');
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int tl=_pr[i],tr=sf[i+1],q=pr[i],_q=pr[n]-q;
		ans+=tl*C(pr[n],q+tl-tr)%mod;
		ans+=q*C(pr[n]-1,q+tl-tr)%mod;
		ans%=mod;
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}