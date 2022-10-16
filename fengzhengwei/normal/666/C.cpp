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
	(op||((*s++=c)&&s==t))&&((fwrite(buf,1,s-buf,stdout)),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=1e5+5;
int T,len;
char s[xx];
ll ans[xx];
ll jiec[xx],ni[xx];
const int mod=1e9+7;
ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
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
void run()
{
	ll ni=ksm(26,mod-2),pw26=ksm(ni,len),pw25=1;
	for(int i=0;i<len;i++)ans[i]=0;
	for(int i=len;i<=1e5;i++)
	{
		ans[i]=(ans[i-1]+C(i-1,len-1)*pw25%mod*pw26%mod)%mod;
		pw25*=25,pw25%=mod;
		pw26*=ni,pw26%=mod;
	}
}
vector<pair<int,int> >v[xx];
ll res[xx];
int main(){
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	T=read();
	scanf("%s",s);
	len=strlen(s);
	int tt=0;
	while(T--)
	{
		int op=read();
		if(op==1)
		{
			scanf("%s",s);
			len=strlen(s);
		}
		else 
		{
			int n=read();
			tt++;
			v[len].push_back(make_pair(n,tt));
		}
	}
	for(int i=1;i<=1e5;i++)
	{
		if(v[i].size())
		{
			len=i;
			run();
			for(auto it:v[i])
				res[it.second]=ans[it.first]*ksm(26,it.first)%mod;
		}
	}
	for(int i=1;i<=tt;i++)cout<<res[i]<<"\n";
	pc('1',1);
	return 0;
}