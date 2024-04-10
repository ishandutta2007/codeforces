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
int n,m,k,q,a[xx],b[xx];
char s[xx];
map<int,int>mp;
vector<pair<int,int> >ans;
void in(int p,int x)//px 
{
	ans.push_back(make_pair(p,x));
//	for(int i=1;i<=m;i++)b[i]=a[i];
//	int tt=0;
//	for(int i=1;i<=m;i++)
//	{
//		a[++tt]=b[i];
//		if(i==p)a[++tt]=x,a[++tt]=x;
//	}
//	m=tt;
}
int main(){
	int T=read();
	while(T--)
	{
		ans.clear();
		n=read();
		mp.clear();
		for(int i=1;i<=n;i++)a[i]=read(),mp[a[i]]++;
		int cr=1;
		for(int i=1;i<=n;i++)
		{
			if(mp[a[i]]%2!=0)
			{
				cr=0;
				break;
			}
		}
		if(!cr)
		{
			puts("-1");
			continue;
		}
		vector<int>res;
		m=n;
		int dlt=0;
		for(int i=1;i<=n;i++)
		{
			int id=0;
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]==a[i])
				{
					id=j;
					break;
				}
			}
			res.push_back((id-i)*2);
			int tt=0;
			vector<int>lin;
			for(int j=i+1;j<id;j++)
			{
				lin.push_back(a[j]);
				in(id+tt+dlt,a[j]);
//				cout<<id+j<<" "<<
				tt++;
			}
			reverse(lin.begin(),lin.end());
			int oo=i+2;
			for(auto it:lin)a[oo]=it,oo++;
			// 
			i=i+1;// 
			dlt+=lin.size();
			dlt+=lin.size();
		}
		cout<<ans.size()<<"\n";
		for(auto it:ans)
			cout<<it.first<<" "<<it.second<<"\n";
		cout<<res.size()<<"\n";
		for(auto it:res)cout<<it<<" ";
		puts("");
	}
	pc('1',1);
	return 0;
}