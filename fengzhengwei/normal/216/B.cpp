#include<bits/stdc++.h>
#define ll long long
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
int n,m;
const int xx=105;
struct nod{int next,to;}e[xx<<1];
int cnt,h[xx],vis[xx];
void add(int x,int y){cnt++;e[cnt]={h[x],y};h[x]=cnt;}
int d[xx],num,n1;
void dfs(int x)
{
	num++,n1+=d[x],vis[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(vis[e[i].to])continue;
		dfs(e[i].to);
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
		d[a]++,d[b]++;
	}
	int rem=0;
	int nd=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		num=0,n1=0;
		dfs(i);
		if(num==(n1/2))
		{
//			if(num==3)
//			{
//				rem+=2,nd^=1;
//			}
//			else 
				if(num&1)rem++;
		}
		else 
		{
			if(num&1)nd^=1;
		}
	}
	cout<<rem+nd<<"\n";
	pc('1',1);
	return 0;
}