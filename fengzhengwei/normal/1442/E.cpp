#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;else if(c==EOF)return -1;
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
struct nod{int next,to;}e[xx<<1];
int cnt,h[xx],c[xx],_c[xx];
void add(int x,int y){cnt++;e[cnt]={h[x],y};h[x]=cnt;}
int C,bcc,bel[xx];
void run(int x)
{
	if(bel[x])return;
	if(c[x]!=C)return;
	bel[x]=bcc;
	for(int i=h[x];i;i=e[i].next)run(e[i].to);
}
int f[xx][3],ans;
void dfs(int x,int y)
{
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
	}
	//f[x][0] 
	f[x][1]=f[x][2]=0;// 
	if(_c[x])
	{
		f[x][_c[x]]=1;// 
		for(int i=h[x];i;i=e[i].next)
		{
			if(e[i].to==y)continue;
			assert(_c[e[i].to]!=_c[x]);
			if(_c[e[i].to]==0)
			{
				ans=max(ans,f[x][_c[x]]+max(f[e[i].to][_c[x]]-1,f[e[i].to][3-_c[x]]));
				f[x][_c[x]]=max(f[x][_c[x]],f[e[i].to][_c[x]]),f[x][_c[x]]=max(f[x][_c[x]],f[e[i].to][3-_c[x]]+1);
			}
			else 
			{
				ans=max(ans,f[x][_c[x]]+f[e[i].to][3-_c[x]]);
				f[x][_c[x]]=max(f[x][_c[x]],f[e[i].to][3-_c[x]]+1);
			}
		}
		ans=max(ans,f[x][_c[x]]);
	}
	else 
	{
		for(int i=h[x];i;i=e[i].next)
		{
			if(e[i].to==y)continue;
			assert(_c[e[i].to]!=_c[x]);
			ans=max(ans,f[x][_c[e[i].to]]+f[e[i].to][_c[e[i].to]]-1);
			ans=max(ans,f[x][3-_c[e[i].to]]+f[e[i].to][_c[e[i].to]]);
			f[x][_c[e[i].to]]=max(f[x][_c[e[i].to]],f[e[i].to][_c[e[i].to]]);
		}
	}
}
signed main(){
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++)c[i]=read(),bel[i]=0;
		memset(h,0,sizeof(h[0])*(n+1));
		cnt=0;
		vector<pair<int,int> >v;
		for(int i=1;i<n;i++)
		{
			int a=read(),b=read();
			v.push_back(make_pair(a,b));
			add(a,b),add(b,a);
		}
		bcc=0;
		for(int i=1;i<=n;i++)
			if(!bel[i])++bcc,C=c[i],run(i),_c[bcc]=C;
		memset(h,0,sizeof(h[0])*(n+1));
		cnt=0;
		for(auto it:v)
		{
			if(bel[it.first]!=bel[it.second])
			add(bel[it.first],bel[it.second]),add(bel[it.second],bel[it.first]);
		}
		ans=0;
		dfs(1,0);
		//ans=0 
		cout<<(ans+2)/2<<"\n";
	}
	pc('1',1);
	return 0;
}