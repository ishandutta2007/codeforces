#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
namespace ppprrr{const int xx=2,mod=2;ll ksm(ll a,ll b){ll ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod,b>>=1;}return ans;}

ll jiec[xx],ni[xx];
ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
void pre()
{
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
}
	
int prim[xx],mn[xx],Cnt;
void pre(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!mn[i])mn[i]=i,prim[++Cnt]=i;
		for(int j=1;j<=Cnt;j++)
		{
			if(prim[j]*i>n)break;
			mn[i*prim[j]]=prim[j];
			if(i%prim[j]==0)break;
		}
	}
}


int lb(int x){return x&-x;}
ll sum[xx];
void Add(int x,int y){for(;x<xx;x+=lb(x))sum[x]+=y;}
ll ask(int x){ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}

struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}


}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
//co 
const int xx=1e6+5,mod=998244353;
//mod1e9+7998 
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
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
struct pr{int x,y;};
int n,m,k,q,a[xx],b[xx];
char s[xx];
ll f[xx];
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	f[0]=1;
	f[1]=1;
	//54 
	//44  
	for(int i=2;i<=44;i++)
	{
		f[i]=f[i-1]+f[i-2];
		if(f[i]>1e9)
		{
//			cerr<<i<<"\n";
			break;
		}
	}
	int T=read();
	while(T--)
	{
//		cerr<<T<<"%%\n";
		int n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		ll sum=0;
		for(int i=n;i>=1;i--)
			sum+=a[i];
		ll ns=0;
		int ty=-1;
		for(int i=0;i<=44;i++)
		{
			ns+=f[i];
//			cerr<<ns<<"##\n";
			if(ns==sum)
			{
				ty=i;
				break;
			}
		}
//		cerr<<sum<<" "<<ns<<"$$\n";
		if(ty==-1)
		{
			puts("NO");
			continue;
		}
		// 
		int cr=1;
		vector<int>t(ty+10);
		// 
		int jc=n+1,lst=-1;
		for(int i=n;i>=1;i--)
		{
			int nw=a[i];
			for(int j=ty;j>=0;j--)
			{
				if(t[j])continue;
				if(nw<f[j])continue;
				if(nw>f[j])
				{
					t[j]=i;
					nw-=f[j];
					--j;
//				cerr<<i<<" "<<nw<<"qq$$\n";
				}
				else if(nw==f[j]&&(j%2==0))
				{
					t[j]=i;
					nw-=f[j];
					--j;
				}
				else 
				{
					if(nw==f[j])
					{
						if(i<jc&&lst==-1)
						{
//							cerr<<"ASD\n";
							lst=i;
							continue;// 
						}
						else 
						{
							t[j]=i;
							nw-=f[j];
							--j;//   
						}
					}
					
				}
			}
			if(nw!=0)
			{
//				cerr<<jc<<" "<<lst<<"$$\n";
				if(lst==-1)
				{
					cr=0;
					break;
				}
				jc=lst,lst=-1;
				for(int j=0;j<=ty;j++)if(t[j]<=jc)t[j]=0;
//				,cerr<<j<<"##\n";
//			cerr<<i<<" "<<jc<<"$$\n";
				i=jc+1;
//				continue;
			}
//			cerr<<nw<<"%%\n";
		}
//		for(int i=0;i<=ty;i++)
//		{
//			if(!t[i])
//			{
//				cerr<<i<<"$$\n";
//				for(int j=1;j<=n;j++)cout<<a[j]<<" ";
//				puts("");
//			}
//			assert(t[i]);
//		}
		if(cr)puts("YES");
		else puts("NO");
	}
	// 
//	ll ans=0;
//	for(int i=1;i<=31;i+=2)
//		ans+=f[i];
//	cout<<ans<<" "<<f[32]<<"\n";
	
	pc('1',1);
	return 0;
}
/*
1
3
29 13 12
*/