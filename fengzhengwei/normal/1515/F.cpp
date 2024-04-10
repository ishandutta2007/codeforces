// LUOGU_RID: 91529511
#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ld long double
#define ull unsigned ll 
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
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=3e5+5;
struct nod
{
	int next,to,i;
}e[xx<<1];
int cnt,h[xx];
void add(int x,int y,int z){cnt++,e[cnt]={h[x],y,z},h[x]=cnt;}
int n,m,X,a[xx],vis[xx],use[xx];
void dfs(int x,int y)
{
	vis[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(vis[e[i].to])continue;
		dfs(e[i].to,x),use[e[i].i]=1;
	}
}
int f[xx];
vector<int>ans;
ll s[xx];
void down(int x)
{
	vector<int>T;
	for(int i=h[x];i;i=e[i].next)
	{
		if(!use[e[i].i])continue;
		if(e[i].to==f[x])continue;
		T.push_back(i);
//		ans.push_back(e[i].i);
//		if(s[e[i].to]<0)down(e[i].to);
	}
	sort(T.begin(),T.end(),[&](int a,int b){return s[e[a].to]>s[e[b].to];});
	for(auto i:T)
	{
		ans.push_back(e[i].i);
		if(s[e[i].to]<0)down(e[i].to);
	}
}
void dfss(int x,int y)
{
//	cerr<<x<<"#\n";
	s[x]=a[x],f[x]=y;
	for(int i=h[x];i;i=e[i].next)
	{
		if(!use[e[i].i]||e[i].to==y)continue;
		dfss(e[i].to,x),s[x]+=s[e[i].to],s[x]-=X;
	}
	if(s[x]>=0)down(x);
}
// >0  
int main(){
//	freopen("a.in","r",stdin);
	n=read(),m=read(),X=read();
	ll sum=0;
	for(int i=1;i<=n;i++)a[i]=read(),sum+=a[i];
	sum-=1ll*(n-1)*X;
	if(sum<0)puts("NO"),exit(0);
	for(int i=1;i<=m;i++)
	{
//		cerr<<i<<"#\n";
		int x=read(),y=read();
		add(x,y,i),add(y,x,i);
	}
	dfs(1,0),dfss(1,0);
	puts("YES");
	for(auto it:ans)cout<<it<<"\n";
	puts("");
	pc('1',1);
	return 0;
}



}signed main(){return ifzw::main();}