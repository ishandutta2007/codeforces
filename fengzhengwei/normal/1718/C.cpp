#pragma GCC diagnostic error "-std=c++2a"

#pragma GCC optimize(2)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define dd double
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
const int xx=2e5+5,mod=998244353;
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
struct SET
{
	priority_queue<ll>inc,dec;
	void cls()
	{
		priority_queue<ll>().swap(inc);
		priority_queue<ll>().swap(dec);
	}
	void erase(ll x)
	{
		dec.push(x);
	}
	void push(ll x)
	{
		inc.push(x);
	}
	ll top()
	{
		while(inc.size()&&dec.size()&&inc.top()==dec.top())inc.pop(),dec.pop();
		return inc.top();
	}
}s;
//map<pair<int,int>,multiset<ll> >mp;
//map<pair<int,int>,ll >mp;
vector<ll>v[xx];
vector<int>yz;
void reb()
{
	s.cls();
	for(auto i:yz)
	{
		for(int j=1;j<=i;j++)
		{
			v[i][j]=0;
			int k=j;
			while(k<=n)v[i][j]+=a[k],k+=i;
			s.push(v[i][j]*i);
		}
	}
}
int main(){
//	freopen("a.out","w",stdout);
	int T;
	T=read();
	while(T--)
	{
		yz.clear();
		s.cls();
		n=read(),q=read();
		ll ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<n;i++)vector<ll>().swap(v[i]);
		vector<int>yy;
		int uu=n;
		for(int i=2;i<=uu;i++)
		{
			if(uu%i==0)yy.push_back(i);
			while(uu%i==0)uu/=i;
		}
		yy.push_back(1);
		for(auto it:yy)if(it!=1)yz.push_back(n/it);
		
		for(auto i:yz){
				
				v[i].resize(i+2);
				for(int j=1;j<=i;j++)
				{
					int k=j;
					while(k<=n)v[i][j]+=a[k],k+=i;
					s.push(v[i][j]*i);
				}
			}
		//} 
		cout<<s.top()<<"\n";
		while(q--)
		{
	//		if(q%55000==0)
	//			reb();
			int x=read(),y=read();
			for(auto i:yz)
			{
				int mn=(x-1)%i+1;
				auto &V=v[i][mn];
				s.erase(V *i);
				V-=a[x];
				V+=y;
				s.push(V *i);
			}
			a[x]=y;
			cout<<s.top()<<"\n";
		}
	}
	pc('1',1);
	return 0;
}