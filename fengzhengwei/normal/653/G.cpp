#include<bits/stdc++.h>
#define ll long long 
#define LL __int128
#define ull unsigned ll
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;};return *s++;}
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
void wt(LL x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(LL x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=3e5+5,mod=1e9+7;
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1ll*a*ans%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return ans;
}
int n,jiec[xx],ni[xx];
int C(int n,int m){return 1ll*jiec[n]*ni[m]%mod*ni[n-m]%mod;}
int pf[xx],t[xx],vs[xx],pr[xx],num[xx],a[xx];
signed main(){
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=1ll*jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=1ll*ni[i+1]*(i+1)%mod;
	
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),t[a[i]]++;
	
	pf[0]=1;
	for(int i=1;i<=n-1;i++)pf[i]=(pf[i-1]+C(n-1,i))%mod;
	
	ll ans=0;
	for(int i=2;i<xx;i++)
	{
		if(!vs[i])
		{
			vector<int>v;
			for(int j=i;j<xx;j+=i)
			{
				num[j]=1;
				if((j/i)%i==0)num[j]=num[j/i]+1;
				vs[j]=1;
				for(int k=0;k<t[j];k++)v.push_back(num[j]);
			}
			sort(v.begin(),v.end());
//			if(v.size())
//			{
//			cerr<<i<<" "<<v.size()<<"@#\n";
//			for(auto it:v)cout<<it<<' ';
//			puts("");
//			}
			for(int I=0;I<(v.size());I++)
			{
				int i=I+(n-v.size()+1);
				ans+=1ll*v[I]*(1ll*pf[i-2<0?n:i-2]%mod-(pf[n-1]-pf[i-1]+mod)%mod+mod)%mod;
//			if(v.size())cout<<ans<<"#$\n";
				ans%=mod;
			}
//			if(v.size())cout<<ans<<"#$\n";
		}
	}
	cout<<ans<<"\n";
	
	pc('1',1);
	return 0;
}