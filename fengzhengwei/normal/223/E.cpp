#include<bits/stdc++.h>
#define ll long long
#define dd double
#define LL __int128
#define ull unsigned ll
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc//
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
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
char ST;// 
const int xx=4e5+5;
struct pt{ll x,y;}p[xx<<1];
pt operator-(const pt&A,const pt&B){return {A.x-B.x,A.y-B.y};}
ll cross(pt&A,pt&B,pt&C){return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);}
struct nod{int next,to,id;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y,int z){cnt++,e[cnt]={h[x],y,z},h[x]=cnt;}
#define fi first 
#define se second
#define Pr pair<int,int>
pt X;
bool cmp(int A,int B){return atan2(p[A].y-X.y,p[A].x-X.x)<atan2(p[B].y-X.y,p[B].x-X.x);}
bool cmp2(pair<int,int> A,pair<int,int> B){return cmp(A.first,B.first);}
vector<Pr>v[xx];
Pr info[xx];
int n,m,k,bel[xx],vis[xx],tt;
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
ll eg[xx];
vector<int>pi;
void run(int x)
{
	pi.push_back(info[x].fi);
	if(bel[x])return;
	bel[x]=tt;
	int to=info[(x^1)].fi;
	run(v[to][(info[(x^1)].se+1)%v[to].size()].se);
}
int f[xx],cr[xx];
ll s[xx],s_[xx];
void dfs(int x,int y)
{
	f[x]=y,vis[x]=1,s[x]=eg[x],s_[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(vis[e[i].to])continue;
		cr[e[i].id]=cr[e[i].id^1]=1,dfs(e[i].to,x),s[x]+=s[e[i].to],s_[x]+=s_[e[i].to];
	}
//	cerr<<x<<" "<<s[x]<<" "<<s_[x]<<"#\n";
}
int a[xx];
int gid(int x,int y)
{
	X=p[x];
	return lower_bound(v[x].begin(),v[x].end(),(Pr){y,0},cmp2)->se;
}
char ED;
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		v[a].push_back({b,(i-1)*2});
		v[b].push_back({a,(i-1)*2^1});
	}
	for(int i=1;i<=n;i++)p[i].x=read(),p[i].y=read();
	//2i -1 
	for(int i=1;i<=n;i++)X=p[i],sort(v[i].begin(),v[i].end(),cmp2);
	for(int i=1;i<=n;i++)
	{
		int re=0;
		for(auto &it:v[i])info[it.se]={i,re++};
	}
	// id  ->  
	int out=0;
	for(int i=0;i<m+m;i++)
	if(!bel[i])
	{
		pi.clear();
		++tt,run(i);
		eg[tt]=pi.size()-1;// 
		//
		ll area=0;
		for(int j=0;j<(int)pi.size() -1;j++)
			area+=cross(p[pi[0]],p[pi[j]],p[pi[j+1]]);
		if(area>0)assert(!out),out=tt;
	}
	assert(out);
	for(int i=0;i<m+m;i+=2)add(bel[i],bel[i^1],i),add(bel[i^1],bel[i],i^1);
	dfs(out,0);
	k=read();
	while(k--)
	{
		int d=read();
		for(int i=1;i<=d;i++)a[i]=read();
		a[d+1]=a[1];
		ll x=0,y=0;
		for(int i=1;i<=d;i++)
		{
			int id=gid(a[i],a[i+1]);
			if(cr[id])
			{
				if(f[bel[id^1]]==bel[id])x+=s_[bel[id^1]],y+=s[bel[id^1]];
				if(f[bel[id]]==bel[id^1])x-=s_[bel[id]],y-=s[bel[id]];
			}
		}
		if(y<0)y*=-1,x*=-1;
		++x;
		y+=d,y/=2;
		cout<<y-x+2<<"\n";
	}
	pc('1',1);
	return 0;
}
/*
6 8
1 2 
1 4
1 5
2 3
3 4
3 6
2 6
5 6

0 0
4 0
3 1
1 2
0 3
5 3

5

4 1 2 3 4
4 2 1 4 3
5 1 4 3 6 5
4 1 2 6 5
4 6 2 1 5
*/