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
const int xx=2e5+5;
const int mod=998244353;
ll jiec[xx];
ll ni[xx];
ll C(ll n,ll m)
{
	return jiec[n]*ni[m]%mod*ni[n-m]%mod;
}
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
ll X[xx];
struct nod
{
	ll a,b;
	bool operator<(const nod&w)const{return a<w.a;}
}e[xx];
int id[xx];
int An[xx];
char S[12][xx/5];
int t[xx],wz[xx];
int n,m;
void pai()
{
	for(int i=1;i<=100;i++)t[i]=0;
	for(int i=1;i<=m;i++)t[e[i].a+50]++;
	for(int i=1;i<=100;i++)t[i]+=t[i-1];
	for(int i=1;i<=m;i++)wz[t[e[i].a+50]--]=i;
//	,cerr<<t[e[i].a+50]<<"QQQ\n";
}
int lin[xx];
int main(){
	int T=read();
	while(T--)
	{
		n=read(),m=read();
		for(int i=1;i<=n;i++)
			X[i]=read();
		ll ans=-1e9;
		for(int i=1;i<=n;i++)scanf("%s",S[i]+1);
		for(int s=0;s<(1<<n);s++)
		{
			ll res=0;
			for(int i=1;i<=n;i++)
			{
				if(s>>(i-1)&1)//1val-x 
					res-=X[i],id[i]=1;
				else res+=X[i],id[i]=-1;
			}
			
			for(int i=1;i<=m;i++)e[i].a=0;
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=n;j++)e[i].a+=(S[j][i]=='1')*id[j];
				// 
				e[i].b=i;
			}
//			cout<<res<<"QWRETRT\n";
//			for(int i=1;i<=n;i++)cout<<id[i]<<"#$@\n";
//			for(int i=1;i<=m;i++)cout<<e[i].a<<"#$@\n";
			
//			sort(e+1,e+m+1);
			
			pai();
			
			for(int i=m;i>=1;i--)lin[wz[i]]=i;
			
			ll R=0;
			for(int i=1;i<=m;i++)
			{
				R+=lin[i]*e[i].a;
			}
			R+=res;
//			cout<<R<<"QWEWQ\n";
			if(ans<R)
			{
				ans=R;
//				for(int i=1;i<=m;i++)cout<<lin[i]<<"QWETERTRE\n";
				for(int i=1;i<=m;i++)
				{
					An[i]=lin[i];
				}
			}
			
			
		}
//		cout<<ans<<"QWEQWE\n";
		for(int i=1;i<=m;i++)cout<<An[i]<<" \n"[i==m];
	}
	pc('1',1);
	return 0;
}