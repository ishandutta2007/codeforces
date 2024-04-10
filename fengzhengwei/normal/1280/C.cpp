#include<bits/stdc++.h>
#define ll long long
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
	pc(x%10+'0',0);
}
void wts(int x,char op)
{
	if(x<0)x=-x,pc('-',0);
	wt(x),pc(op,0);
}
int n;
const int xx=3e5+5;
struct nod
{
	int next,to,v;
}e[xx<<1];
int cnt,h[xx];
void add(int x,int y,int z){cnt++;e[cnt]={h[x],y,z};h[x]=cnt;}
int siz[xx];
ll ans0,ans1;
void dfs(int x,int y)
{
	siz[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		siz[x]+=siz[e[i].to];
		ans0+=(siz[e[i].to]&1)?e[i].v:0;
		ans1+=1ll*e[i].v*min(siz[e[i].to],n-siz[e[i].to]);
	}
}
signed main(){
	int T=read();
	while(T--)
	{
		ans0=0,ans1=0;
		n=read()*2;
		memset(h,0,sizeof(h[0])*(n+1));
		memset(e,0,sizeof(e[0])*(cnt+1));
		cnt=0;
		for(int i=1;i<n;i++)
		{
			int a=read(),b=read(),c=read();
			add(a,b,c),add(b,a,c);
		}
		dfs(1,0);
		cout<<ans0<<" "<<ans1<<"\n";
	}
	pc('1',1);
	return 0;
}