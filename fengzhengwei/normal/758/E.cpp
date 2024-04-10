#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
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
const int xx=2e5+5;
struct nod{int next,to;ll a,b;}e[xx<<1];
int cnt=1,h[xx],bel[xx],U[xx],V[xx],n;
void add(int x,int y,int a,int b){cnt++;e[cnt]={h[x],y,a,b},h[x]=cnt;}
ll mn[xx],mx[xx],sm[xx],red[xx],cr=1;
void dfs(int x,int y)
{
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		if(mn[e[i].to]>e[i].b){cr=0;break;}
		sm[x]+=sm[e[i].to]+e[i].a;
		mx[e[i].to]=min(mx[e[i].to],e[i].b);
		mx[x]+=min(mx[e[i].to],e[i].b)+e[i].a;
		mn[x]+=mn[e[i].to]+e[i].a-min(e[i].a-1,e[i].b-(mn[e[i].to]));
	}
}
void dfss(int x,int y)
{
//	cerr<<x<<" "<<red[x]<<" "<<sm[x]<<" "<<mx[x]<<"!\n";
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		red[e[i].to]+=sm[e[i].to]-mx[e[i].to];
		red[x]-=red[e[i].to];
	}
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		ll dlt=min(red[x],mx[e[i].to]-mn[e[i].to]);
		red[e[i].to]+=dlt,red[x]-=dlt;
		
		dlt=min(red[x],min(e[i].a-1,e[i].b-(mn[e[i].to])));
		e[i].a-=dlt,e[i].b-=dlt,e[i^1].a-=dlt,e[i^1].b-=dlt,red[x]-=dlt;
		dfss(e[i].to,x);
	}
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read(),c=read(),d=read();
		add(a,b,c,d),add(b,a,c,d);
		bel[i]=cnt,U[i]=a,V[i]=b;
	}
	dfs(1,0);
	if(!cr)puts("-1");
	else 
	{
		red[1]=sm[1]-mx[1];
		dfss(1,0);
		cout<<n<<"\n";
		for(int i=1;i<n;i++)cout<<U[i]<<" "<<V[i]<<" "<<e[bel[i]].a<<" "<<e[bel[i]].b<<"\n"; 
	}
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}