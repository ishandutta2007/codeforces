#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
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
int n,m;
const int xx=2e6+5;
struct nod
{
	int next,to;
}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
int rd[xx],cd[xx];
int io[xx],ii[xx];
int vis[xx];
void dfs(int x)
{
	if(vis[x])return ;
	vis[x]=1;
	for(int i=h[x];i;i=e[i].next)if(!vis[e[i].to])dfs(e[i].to);
}
int ct[xx];
signed main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		add(a,b);
		rd[b]++,cd[a]++;
	}
	vector<int>sour,sink;
	int cst=0;
	for(int i=1;i<=n;i++)if(!rd[i])sour.push_back(i),io[i]=++cst;
	cst=0;
	for(int i=1;i<=n;i++)if(!cd[i])sink.push_back(i),ii[i]=++cst;
	for(int i=1;i<=(int)sour.size();i++)
	{
		for(int j=1;j<=n;j++)vis[j]=0;
		dfs(sour[i-1]);
		int re=0;
		for(int j=1;j<=(int)sink.size();j++)
			if(vis[sink[j-1]])re+=(1<<(j-1));
		ct[re]++;
	}
	for(int i=1;i<=n;i++)if(!rd[i]&&!cd[i])puts("NO"),exit(0);
	for(int j=0;j<20;j++)
		for(int i=0;i<(1<<20);i++)
			if(i>>j&1)ct[i]+=ct[i-(1<<j)];
	for(int i=1;i<(1<<(int)sink.size())-1;i++)
		if(ct[i]>=__builtin_popcount(i))puts("NO"),exit(0);
	puts("YES");
	pc('1',1);
	return 0;
}