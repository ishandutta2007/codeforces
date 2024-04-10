#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ull unsigned ll 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
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
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
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
const int mod=1e9+7;
const int xx=1e6+5;
int T,n,f[xx];
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return ans;
}
ll g[xx],pw[xx];
int main(){
//	freopen("a.in","r",stdin);
	T=read();
	while(T--)
	{
		n=read();
		f[n]=1,g[n]=2,g[n+1]=1;
		for(int i=n-1;i>=1;i--)
			g[i]=g[i+1],f[i]=(g[i]-(i+i<=n?g[i+i]:0)+mod)%mod,g[i]=(g[i]+f[i])%mod;
//			,cerr<<i<<" "<<f[i]<<"#\n";
		pw[0]=1;
		for(int i=1;i<=n;i++)pw[i]=(pw[i-1]*2)%mod;
		int iv=ksm(pw[n],mod-2);
		for(int i=1;i<=n;i++)
		{
			if(i==1)cout<<(n==1)<<"\n";
			else cout<<pw[i/2]*f[i]%mod*iv%mod*(1+(i==n))%mod<<"\n";
		}
	}
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}