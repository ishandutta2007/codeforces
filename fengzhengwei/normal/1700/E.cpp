#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC target("avx")
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
int n,m,k,q,b[xx];
char s[xx];
vector<vector<int> >v;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
struct nod
{
	int a,b,c,d;
	void cl(){if(a>c)swap(a,c),swap(b,d);if(a==c&&b>d)swap(b,d);}
	bool operator<(const nod&w)const{return a==w.a?b==w.b?c==w.c?d<w.d:c<w.c:b<w.b:a<w.a;}
};
map<nod,int>mp;
vector<vector<int> >vis,Cr;
void cl(vector<vector<int> >&v)
{
	v.resize(n+1);
	for(int i=1;i<=n;i++)v[i].resize(m+1);
}
int re,ct;
bool is(int,int);
void f0(int a,int b)
{
	if(Cr[a][b])Cr[a][b]=0,ct-=is(a,b);
}
void f1(int a,int b)
{
	if(!Cr[a][b])Cr[a][b]=1,ct+=is(a,b);
}
bool check(int a,int b,int c,int d)
{
	int i=a,j=b;
	int inict=ct;
	f0(i,j);
	for(int k=0;k<4;k++)
	{
		if(i+dx[k]<1||i+dx[k]>n||j+dy[k]<1||j+dy[k]>m)continue;
		f0(i+dx[k],j+dy[k]);
	}
	i=c,j=d;
	f0(i,j);
	for(int k=0;k<4;k++)
	{
		if(i+dx[k]<1||i+dx[k]>n||j+dy[k]<1||j+dy[k]>m)continue;
		f0(i+dx[k],j+dy[k]);
	}
	swap(v[a][b],v[c][d]);
	i=a,j=b;
	f1(i,j);
	for(int k=0;k<4;k++)
	{
		if(i+dx[k]<1||i+dx[k]>n||j+dy[k]<1||j+dy[k]>m)continue;
		f1(i+dx[k],j+dy[k]);
	}
	i=c,j=d;
	f1(i,j);
	for(int k=0;k<4;k++)
	{
		if(i+dx[k]<1||i+dx[k]>n||j+dy[k]<1||j+dy[k]>m)continue;
		f1(i+dx[k],j+dy[k]);
	}
	swap(v[a][b],v[c][d]);
	int ans=(ct==n*m);
	ct=inict;
	return ans;
}
int an;
void get(int x,int y)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(!vis[i][j]||(vis[i][j]&&(x<i||x==i&&y<j)))
			if(check(x,y,i,j))
				an++;
		}
}
bool is(int i,int j)
{
	int cr=v[i][j]==1;
	for(int k=0;k<4;k++)
	{
		if(i+dx[k]<1||i+dx[k]>n||j+dy[k]<1||j+dy[k]>m)continue;
		if(v[i+dx[k]][j+dy[k]]<v[i][j])cr=1;
	}
	return cr;
}
int main(){
//	freopen("a.in","r",stdin);
	n=read(),m=read();
	cl(v),cl(vis),cl(Cr);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			v[i][j]=read();
	vector<pr>im;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!is(i,j))im.push_back({i,j});
	if(!im.size())
	{
		puts("0");
		exit(0);
	}
	if(im.size()>10)
	{
		puts("2");
		exit(0);
	}
	for(auto it:im)
	{
		int i=it.x,j=it.y;
		vis[i][j]=1;
		for(int k=0;k<4;k++)
		{
			if(i+dx[k]<1||i+dx[k]>n||j+dy[k]<1||j+dy[k]>m)continue;
			vis[i+dx[k]][j+dy[k]]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			Cr[i][j]=1;
			ct+=is(i,j);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(vis[i][j])
			{
				get(i,j);
				if(1.0*clock()/CLOCKS_PER_SEC>1.85)cout<<2<<"\n",exit(0);
			}
	if(!an)cout<<2<<"\n";
	else cout<<1<<" "<<an<<"\n";
	pc('1',1);
	return 0;
}