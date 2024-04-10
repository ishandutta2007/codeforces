#include<bits/stdc++.h>
#define ll long long
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
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
const int xx=2e5+5;
int n;
namespace tp
{
	struct nod{int next,to;}e[xx<<1];
	int cnt,h[xx],ds[xx];
	void add(int x,int y)
	{
		if(!x||!y)return;
		cnt++;
		e[cnt].next=h[x];
		h[x]=cnt;
		e[cnt].to=y;
		ds[y]++;
	}
	void out()
	{
		queue<int>q;
		for(int i=1;i<=n;i++)
			if(!ds[i])q.push(i);
		while(!q.empty())
		{
			int x=q.front();
			cout<<x<<"\n";
			q.pop();
			for(int i=h[x];i;i=e[i].next)
				if(!(--ds[e[i].to]))q.push(e[i].to);
		}
	}
}
struct nod{int next,to;}e[xx<<1];
int cnt,h[xx],ds[xx];
void add(int x,int y)
{
	if(!x||!y)return;
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
	ds[y]++;
}
int d[xx];
void dfs(int x,int y)
{
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
	}
	if(d[x]&1)
	{
		if(!y){puts("YES"),exit(0);}
		tp::add(x,y);//x 
		d[x]^=1;
	}
	else tp::add(y,x),d[y]^=1;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)
	{
		int a=read();
		if(a)add(a,i),add(i,a);
	}
	int tt=0;
	for(int i=1;i<=n;i++)
	    if(!(ds[i]&1))tt++;
	if(tt&1)
	{
	    puts("YES");
	}
	else 
	{
	    puts("NO");exit(0);
	}
	dfs(1,0);
	tp::out();
	pc('1',1);
	return 0;
}