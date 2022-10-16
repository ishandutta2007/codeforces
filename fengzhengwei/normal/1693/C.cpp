#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar g
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
const int xx=2e5+5;
struct no{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
int n,m;
struct nod
{
	int x,dis;
	bool operator<(const nod&w)const{return dis>w.dis;}
};
priority_queue<nod>q;
int dis[xx],d[xx],vis[xx];
signed main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		add(b,a),d[a]++;
	}
	for(int i=1;i<=n;i++)d[i]++;
	memset(dis,0x3f,sizeof(dis));
	dis[n]=0;
	q.push({n,0});
	while(!q.empty())
	{
		int x=q.top().x;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=h[x];i;i=e[i].next)
		{
			--d[e[i].to];
			if(dis[e[i].to]>dis[x]+d[e[i].to])
			{
				dis[e[i].to]=dis[x]+d[e[i].to];
				q.push({e[i].to,dis[e[i].to]});
			}
		}
	}
	cout<<dis[1]<<"\n";
	pc('1',1);
	return 0;
}