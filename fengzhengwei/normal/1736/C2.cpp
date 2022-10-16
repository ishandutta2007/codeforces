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
int n,m,k,q,a[xx],b[xx],mn[xx],se[xx];
namespace s1
{
	int lb(int x){return x&-x;}
	ll sum[xx];
	void add(int x,int y){for(;x<xx;x+=lb(x))sum[x]+=y;}
	ll ask(int x){ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
	ll ask(int l,int r){return l>r?0:ask(r)-ask(l-1);}
}
namespace s2
{
	int lb(int x){return x&-x;}
	ll sum[xx];
	void add(int x,int y){for(;x<xx;x+=lb(x))sum[x]+=y;}
	ll ask(int x){ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
	ll ask(int l,int r){return l>r?0:ask(r)-ask(l-1);}
}
int L[xx],R[xx];
struct pr{int x,y;};
vector<pr>v[xx];
char s[xx];
ll res[xx];
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n+1;i++)mn[i]=n,se[i]=n;
	for(int i=1;i<=n;i++)
	{
		int ty=i-a[i],num=i-1;
		if(ty<=0)continue;
		if(mn[ty]>num)se[ty]=mn[ty],mn[ty]=num;
		else se[ty]=min(se[ty],num);
	}
	for(int i=n;i>=1;i--)
	{
		if(mn[i]>mn[i+1])se[i]=mn[i],mn[i]=mn[i+1];
		else se[i]=min(se[i],mn[i+1]);
		se[i]=min(se[i],se[i+1]);
	}
	ll ans=0;
	for(int i=1;i<=n;i++)ans+=mn[i]-i+1;
	for(int i=1;i<=n;i++)s1::add(i,mn[i]);
	for(int i=1;i<=n;i++)s2::add(i,se[i]);
	for(int i=0;i<=n;i++)L[i]=0,R[i]=-1;
	for(int i=1;i<=n;i++)
	{
		if(!L[mn[i]])L[mn[i]]=i;
		R[mn[i]]=i; 
	}
	for(int i=1;i<=n;i++)
	{
		if(L[i]==0&&R[i]==-1)L[i]=1,R[i]=0;
		else 
		{
			break;
		}
	}
	for(int i=0;i<=n;i++)
		if(!L[i+1])L[i+1]=R[i]+1,R[i+1]=R[i];
	q=read();
	for(int i=1;i<=q;i++)
	{
		int x=read(),y=read();
		v[x].push_back({y,i});
	}
//	for(int i=0;i<=n;i++)cout<<L[i]<<" "<<R[i]<<"#\n";
//	cerr<<"!!\n";
	for(int i=1;i<=n;i++)
	{
		for(auto it:v[i])
		{
			if(it.x<=a[i])
			{
				int ty=i-it.x;
				int l=R[i-1]+1,r=ty,an=ty+1;
				while(l<=r)
				{
					int mid=l+r>>1;
//					cerr<<mid<<"#\n";
					if(mn[mid]>i-1)an=mid,r=mid-1;
					else l=mid+1;
				}
				res[it.y]=ans-s1::ask(an,ty)+1ll*(i-1)*(ty-an+1);
			}
			else 
			{
				int ty=max(i-it.x+1,L[i-1]),r=R[i-1];
//				cerr<<ty<<" "<<r<<" "<<L[i-1]<<" "<<s1::ask(0,0)<<"##\n";
				res[it.y]=ans-s1::ask(ty,r)+s2::ask(ty,r);
			}
		}
	}
	for(int i=1;i<=q;i++)cout<<res[i]<<"\n";
//	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}