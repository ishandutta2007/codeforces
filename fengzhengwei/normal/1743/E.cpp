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

void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
void ad(int &a,ll b){(a=(a+b)%mod);}
int red(int x){return x>=mod?x-=mod:x;}

random_device R;
mt19937 G(218);
int rd(int l,int r){return uniform_int_distribution<int>(l,r)(G);}

}

int gcd(int a,int b){return !b?a:gcd(b,a%b);}
//co 
const int xx=1e6+5,mod=998244353;
//mod1e9+7998 

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

#define Pr pair<int,int>
#define fi first
#define se second
int n,m,k,q,a[xx],b[xx];
char s[xx];
ll A,B,C,D,E,F;
map<vector<ll>,ll>mp;
// 
ll run(vector<ll>s)
{
	if(s[2]<=0)return 0;
	if(mp.count(s))return mp[s];
	ll D1=B-s[0],D2=D-s[1];
	mp[s]=run({0,0,s[2]-(A+C-F)})+max(D1,D2);
	if(mp.size()%100000==0)cerr<<mp.size()<<"\n";
	if(D1<D2)
	{
		mp[s]=min(mp[s],run({0,s[1]+D1,s[2]-(A-F)})+D1);
	}
	if(D1>D2)
	{
		mp[s]=min(mp[s],run({s[0]+D2,0,s[2]-(C-F)})+D2);
	}
//	cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<" "<<mp[s]<<"#\n";
//	if(D1==D2)mp[lim]=run({0,0,s[2]-(A+C-F)})+D1;
//	min({run(lim-(A+C-F))+B+D,run(lim-(A-F))+B,run(lim-(C-F))+D});
	return mp[s];
}
// 
// =0  
ll f[xx];
int main(){
	A=read(),B=read(),C=read(),D=read(),E=read(),F=read();
	// i  
	f[0]=0;
	for(int i=1;i<=5000;i++)f[i]=1e18;
	for(int i=1;i<=5000;i++)
	{
		for(int j=1;j<=5000;j++)
		{
			ll k=j*B/D;
			if(!k)continue;
			k=min(k,5000ll);
			int t1=i-(j-1)*(A-F)-(k-1)*(C-F)-(A+C-F);
			ll tv=t1<=0?0:f[t1];
			f[i]=min(f[i],tv+j*B);
		}
		swap(A,C),swap(B,D);
		for(int j=1;j<=5000;j++)
		{
			ll k=j*B/D;
			if(!k)continue;
			k=min(k,5000ll);
			int t1=i-(j-1)*(A-F)-(k-1)*(C-F)-(A+C-F);
			ll tv=t1<=0?0:f[t1];
			f[i]=min(f[i],tv+j*B);
		}
	}
	ll ans=1e18;
	for(int j=0;j<=5000;j++)
		for(int k=0;k<=5000;k++)
		{
			int t1=E-j*(A-F)-k*(C-F);
			ll tv=t1<=0?0:f[t1];
			ans=min(ans,tv+max(B*j,D*k));
		}
	cout<<ans<<"\n";
	
//	cout<<run({0,0,E})<<"\n";
//	cerr<<mp.size()<<"$\n";
	pc('1',1);
	return 0;
}