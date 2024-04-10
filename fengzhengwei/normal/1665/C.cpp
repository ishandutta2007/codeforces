#include<bits/stdc++.h>
#define ll long long
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
namespace zhs
{
	const int xx=5e5+5,mod=998244353;
	ll jiec[xx],ni[xx];
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
	ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
	void pre()
	{
		jiec[0]=1;
		for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
		ni[xx-1]=ksm(jiec[xx-1],mod-2);
		for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	}
}
namespace pr
{
	const int xx=5e5+5,mod=998244353;
	int prim[xx],mn[xx],cnt;
	void pre(int n)
	{
		for(int i=2;i<=n;i++)
		{
			if(!mn[i])mn[i]=i,prim[++cnt]=i;
			for(int j=1;j<=cnt;j++)
			{
				if(prim[j]*i>n)break;
				mn[i*prim[j]]=prim[j];
				if(i%prim[j]==0)break;
			}
		}
	}
}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
// 
const int xx=5e5+5,mod=998244353;
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
int n,m,k,q,a[xx];
char s[xx];
struct nod
{
	int next,to;
}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;e[cnt]={h[x],y};h[x]=cnt;
}
vector<int>num;
void dfs(int x,int y)
{
	int cr=0;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		cr++;
	}
	if(cr)
	num.push_back(cr);
}
int main(){
	int T=read();
	while(T--)
	{
		n=read();
		memset(h,0,sizeof(h[0])*(n+1));
		cnt=0;
		for(int i=2;i<=n;i++)add(read(),i);
		num.clear();
		dfs(1,0);
		num.push_back(1);
		sort(num.begin(),num.end());
		reverse(num.begin(),num.end());
		int T=num.size();
		vector<int>rem;
		for(int i=0;i<num.size();i++)
			if(num[i]-(num.size()-i)>0)rem.push_back(num[i]-(num.size()-i));
//		cerr<<T<<"ASD\n";
		if(!rem.size())cout<<T<<"\n";
		else 
		{
			int l=0,r=1e9,ans=-1;
			while(l<=r)
			{
				int mid=l+r>>1;
				int cr=1,sum=0;
				for(auto it:rem)
					if(it-mid>0)sum+=it-mid;
				if(sum<=mid)ans=mid,r=mid-1;
				else l=mid+1;
			}
			cout<<T+ans<<"\n";
		}
	}
	pc('1',1);
	return 0;
}