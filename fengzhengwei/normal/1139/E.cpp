#include<bits/stdc++.h>
#define ll long long
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
const int xx=2e5+5;
struct nod{int next,to,v;}e[xx<<1];
int cnt=1,h[xx],p[xx],c[xx],ans[xx],r[xx],vis[5005],my[xx],N,n,m;
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
bool dfs(int x)
{
	vis[x]=1;
	for(int i=h[x];i;i=e[i].next)
		if((my[e[i].to]==-1)||(!vis[my[e[i].to]]&&dfs(my[e[i].to])))return my[e[i].to]=x,1;
	return 0;
}
bool up()
{
	if(N==5000+1)return 0;
	memset(vis,0,sizeof(vis));
	if(dfs(N))return ++N,1;
	return 0;
}
int V[xx];
signed main(){
	memset(my,-1,sizeof(my));
	n=read(),m=read();
	for(int i=1;i<=n;i++)p[i]=read();
	for(int i=1;i<=n;i++)c[i]=read();
	int d=read();
	for(int i=1;i<=d;i++)r[i]=read(),V[r[i]]=1;
	for(int i=1;i<=n;i++)if(!V[i])add(p[i],c[i]);
	for(int i=d;i>=1;i--)
	{
		while(up());
//		for(int j=1;j<=n;j++)cout<<my[j]<<"!! \n";
		ans[i]=N;
		add(p[r[i]],c[r[i]]);
	}
//		while(up());
//		cout<<N<<"!!\n";
	for(int i=1;i<=d;i++)cout<<ans[i]<<"\n";
	pc('1',1);
	return 0;
}