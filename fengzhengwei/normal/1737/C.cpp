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
int main(){
	int T=read();
	while(T--)
	{
		n=read();
		vector<pair<int,int>>v(3);
		for(auto &it:v)it.first=read(),it.second=read();
//		int r1=read(),c1=read();
//		int r2=read(),c2=read();
//		int r3=read(),c3=read();
		int x=read(),y=read();
		#define P pair<int,int> 
		pair<int,int>id={x,y};
		sort(v.begin(),v.end());
		if(v[0].first==1&&v[0].second==1&&v[2].second==1)
		{
			if(id.first==1||id.second==1)
			{
				puts("YES");
				continue;
			}
			else puts("NO");
			continue;
		}
		id.first=n-id.first+1;
		for(auto &it:v)
			it.first=n-it.first+1;
		
		sort(v.begin(),v.end());
		if(v[0].first==1&&v[0].second==1&&v[2].second==1)
		{
			if(id.first==1||id.second==1)
			{
				puts("YES");
				continue;
			}
			else puts("NO");
			continue;
		}
		id.second=n-id.second+1;
		for(auto &it:v)
			it.second=n-it.second+1;
		
		sort(v.begin(),v.end());
		if(v[0].first==1&&v[0].second==1&&v[2].second==1)
		{
//			cerr<<"!\n";
			if(id.first==1||id.second==1)
			{
				puts("YES");
				continue;
			}
			else puts("NO");
			continue;
		}
		
		id.first=n-id.first+1;
		for(auto &it:v)
			it.first=n-it.first+1;
		
		sort(v.begin(),v.end());
		if(v[0].first==1&&v[0].second==1&&v[2].second==1)
		{
			if(id.first==1||id.second==1)
			{
				puts("YES");
				continue;
			}
			else puts("NO");
			continue;
		}
//		cerr<<"!!\n";
		map<int,int>X,Y;
		for(auto it:v)
		{
			X[it.first]++;
			Y[it.second]++;
		}
		int nx=0,ny=0;
		for(auto it:X)if(it.second==1)nx=it.first;
		for(auto it:Y)if(it.second==1)ny=it.first;
//		cerr<<nx<<" "<<ny<<" "<<x<<" "<<y<<"$\n";
		if((id.first-nx)%2==0&&(id.second-ny)%2==0)
		{
			puts("NO");
		}
		else puts("YES");
//		ll ans=0;
//		for(int i=1;i<=n;i++)a[i]=read();
//		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}