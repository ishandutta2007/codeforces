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
vector<int>v[xx];
int mx[5005][5005];
int get(int l,int r)
{
	if(l>r)return 0;
	int ini=(r-l+1)&1;
	// 
	if(mx[l][r]<=(r-l+2)/2)return ini;
	return mx[l][r]-(r-l+1-mx[l][r]);
}
int id[xx];
int f[xx];
int main(){
	int T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<=n;i++)
		{
			v[a[i]].push_back(i);
			id[i]=v[a[i]].size()-1;
		}
		for(int i=1;i<=n;i++)mx[i][i]=1;
		for(int l=1;l<=n;l++)
		{
			for(int i=1,j;(j=(i+l))<=n;i++)
			{
				mx[i][j]=mx[i][j-1];
				if(id[j]-mx[i][j]>=0&&v[a[j]][id[j]-mx[i][j]]>=i)mx[i][j]++;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)f[i]=-1e9;
		f[0]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(a[i]==a[j]||j==0)
				{
					if(get(j+1,i-1)==0)f[i]=max(f[i],f[j]+1);
				}
			}
//			cout<<i<<" "<<f[i]<<" "<<get(1,3)<<" "<<mx[1][3]<<"@\n";
		}
		for(int i=0;i<=n;i++)if(get(i+1,n)==0)ans=max(ans,f[i]);
//		,cerr<<i<<" "<<get(i+1,n)<<" "<<mx[i+1][n]<<"@@\n";
		cout<<ans<<"\n";
//		for(int c=1;c<=n;c++)
//		{
//			int ls=1,res=0;
//			for(int i=1;i<=n;i++)
//			{
//				if(a[i]==c)
//				{
////					if(c==3)cerr<<i<<" "<<res<<" "<<ls<<" "<<i-1<<" "<<mx[ls][i-1]<<" "<<i<<"##\n";
//					res=max(0,res-get(ls,i-1)),res++,ls=i+1;
//					ans=max(ans,res);
//				}
//			}
//		}
//		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}