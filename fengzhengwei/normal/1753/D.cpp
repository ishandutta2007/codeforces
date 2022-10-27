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
int n,m,k,a[xx],b[xx];
int id(int x,int y){return (x-1)*m+y;}
bool ck(int x,int y)
{
	return 1<=x&&x<=n&&1<=y&&y<=m;
}
struct nod{int next,to,v;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y,int z)
{
//	cerr<<x<<" "<<y<<"$$\n";
	cnt++,e[cnt]={h[x],y,z},h[x]=cnt;
}
char s[xx];
#define ad(x,y,a,b,val) {if(ck(x,y)&&ck(a,b)&&mp[x][y]!='#'&&mp[a][b]!='#')add(id(x,y),id(a,b),val),add(id(a,b),id(x,y),val);}
#define ads(x,y,a,b,val) {if(ck(x,y)&&ck(a,b)&&mp[x][y]!='#'&&mp[a][b]!='#')add(id(a,b),id(x,y),val);}
//void ad(int x,int y,int a,int b,int val)
//{
//	
//}
struct nd
{
	int x;
	ll ds;
	bool operator<(const nd&w)const{return ds>w.ds;}
};
ll dis[xx];
int vis[xx];
int main(){
	n=read(),m=read();
	vector<vector<char> >mp(n+2,vector<char>(m+2));
	int p=read(),q=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char c;
			while((c=getchar())!='L'&&c!='R'&&c!='U'&&c!='D'&&c!='#'&&c!='.');
			mp[i][j]=c;
//			cerr<<i<<" "<<j
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='L')
			{
				ads(i,j+1,i,j-1,q);
				ads(i,j,i-1,j+1,p);
				ads(i,j,i+1,j+1,p);
			}
			if(mp[i][j]=='R')
			{
				ads(i,j-1,i,j+1,q);
				ads(i,j,i-1,j-1,p);
				ads(i,j,i+1,j-1,p);
			}
		}
	}
	/*
	4 3
	1 500
	LR.
	#U#
	#D#
	LR.
	*/
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='U')
			{
				ads(i+1,j,i-1,j,q);
				ads(i,j,i+1,j-1,p);
				ads(i,j,i+1,j+1,p);
			}
			if(mp[i][j]=='D')
			{
				ads(i-1,j,i+1,j,q);
				ads(i,j,i-1,j-1,p);
				ads(i,j,i-1,j+1,p);
			}
		}
	}
	int tt=n*m;
	for(int i=1;i<=tt;i++)dis[i]=1e18;
	priority_queue<nd>Q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='.')
			{
				dis[id(i,j)]=0;
				Q.push({id(i,j),0});
			}
		}
	}
	while(!Q.empty())
	{
		int x=Q.top().x;
//		cerr<<x<<"!!\n";
		Q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=h[x];i;i=e[i].next)
		{
			if(dis[e[i].to]>dis[x]+e[i].v)
			{
				dis[e[i].to]=dis[x]+e[i].v;
				Q.push({e[i].to,dis[e[i].to]});
			}
		}
	}
	ll ans=1e18;
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			ans=min(ans,dis[id(i,j)]+dis[id(i,j+1)]);
			
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			ans=min(ans,dis[id(i,j)]+dis[id(i+1,j)]);
	
	if(ans>=1e18)puts("-1");
	else cout<<ans<<"\n";
	pc('1',1);
	return 0;
}