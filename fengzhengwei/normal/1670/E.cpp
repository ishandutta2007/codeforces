#include<bits/stdc++.h>
#define ll long long
#define dd double
#define LL __int128
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
	pc(x%10+'0',0);
}
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
const int xx=3e5+5;
struct nod{int next,to,id;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y,int z){cnt++,e[cnt]={h[x],y,z},h[x]=cnt;}
int val[xx],d[xx],L[xx],R[xx],tt,Ae[xx],n;
void dfs(int x,int y,int ls)
{
	if(x==1)d[x]=val[x];
	else 
	{
		if(d[y]>=n)Ae[ls]=R[tt],val[x]=L[tt];
		else Ae[ls]=L[tt],val[x]=R[tt];
		tt--;
	}
	d[x]=d[y]^n;
//	cout<<x<<' '<<ls<<"$%\n";
	for(int i=h[x];i;i=e[i].next)
		if(e[i].to!=y)dfs(e[i].to,x,e[i].id);
}
signed main(){
	int T=read();
	while(T--)
	{
		n=(1<<read());
		memset(h,0,sizeof(h[0])*(n+1));
		cnt=0;
		for(int i=1;i<n;i++)
		{
			int a=read(),b=read();
			add(a,b,i),add(b,a,i);
		}
		val[1]=n;tt=0;
		for(int i=1;i<n;i++)L[++tt]=i,R[tt]=i+n;
		dfs(1,0,0);
		cout<<1<<"\n";
		for(int i=1;i<=n;i++)cout<<val[i]<<" ";
		puts("");
		for(int i=1;i<n;i++)cout<<Ae[i]<<" ";
		puts("");
	}
	pc('1',1);
	return 0;
}