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
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc(x%10+'0',0);
}
void wts(ll x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=1e5+5;
int n,m;
struct nod{int next,to,v;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y,int z){cnt++;e[cnt]={h[x],y,z};h[x]=cnt;}
int mx,id,d[xx];//1e9 
void dfs(int x,int y,int d)
{
	if(mx<d)mx=d,id=x;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x,d+e[i].v);
	}
}
int lg[xx];
struct tree
{
	int rt;
	int md[xx],dep[xx],son[xx],f[xx][21];
	void dfs(int x,int y)
	{
//		cout<<x<<"!!!\n";
		f[x][0]=y;
		for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1];
		md[x]=dep[x];
		for(int i=h[x];i;i=e[i].next)
		{
			if(e[i].to==y)continue;
			dep[e[i].to]=dep[x]+e[i].v;
			dfs(e[i].to,x);
			if(md[x]<md[e[i].to])son[x]=e[i].to,md[x]=md[e[i].to];
		}
	}
	// 
	//sai 
	//rkid 
	// 
	int ans[xx],id[xx],top[xx],sum[xx],rk[xx],sa[xx],tt;
	void dfss(int x,int y)
	{
//		cerr<<x<<" "<<y<<"ASDDFG \n";
		top[x]=y;
		if(x==y)id[x]=++tt,sum[tt]=md[x]-dep[f[x][0]];
		else id[x]=id[top[x]];
		if(!son[x])return;
		dfss(son[x],y);
		for(int i=h[x];i;i=e[i].next)
		{
			if(e[i].to==f[x][0]||e[i].to==son[x])continue;
			dfss(e[i].to,e[i].to);
		}
	}
	void pre()
	{
		dfs(rt,0),dfss(rt,rt);
//		for(int i=1;i<=tt;i++)cout<<i<<" asda "<<sum[i]<<"!!\n";
		for(int i=1;i<=tt;i++)sa[i]=i;
		sort(sa+1,sa+tt+1,[&](int a,int b){return sum[a]>sum[b];});
		for(int i=1;i<=tt;i++)ans[i]=ans[i-1]+sum[sa[i]];
//		cout<<ans[tt]<<"!!\n";
		for(int i=1;i<=tt;i++)rk[sa[i]]=i;
	}
	int get(int x,int y)
	{
		//xy 
		if(y==1)return md[x];
		if(rk[id[x]]<=y)return ans[y];
//		cerr<<rt<<" sd "<<mx<<"!!\n";
		int X=x;
		for(int i=20;i>=0;i--)if(f[X][i]&&rk[id[f[X][i]]]>y-1)X=f[X][i];
		int mx=ans[y-1]+md[x]-dep[f[X][0]];
		X=x;
		for(int i=20;i>=0;i--)if(f[X][i]&&rk[id[f[X][i]]]>y)X=f[X][i];
//		mx=max(mx,ans[y]+mx[x]-dep[f[X][0]]-(md[f[X][0]]-dep[F[x][0]]));
		mx=max(mx,ans[y]+md[x]-md[f[X][0]]);
		return mx;
	}
}t1,t2;
int main(){
	lg[0]=-1;
	for(int i=1;i<xx;i++)lg[i]=lg[i-1]+(i==(i&-i));
	n=read(),m=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read(),c=read();
		add(a,b,c),add(b,a,c);
		d[a]++,d[b]++;
	}
	int num=0;
	for(int i=1;i<=n;i++)num+=(d[i]==1);
	dfs(1,0,0);
	t1.rt=id;
	mx=0;
	dfs(id,0,0);
	t2.rt=id;
//	cerr<<num<<" "<<t1.rt<<" sss "<<t2.rt<<"\n";
	t1.pre(),t2.pre();
	int lst=0;
	while(m--)
	{
		int x=(read()+lst-1)%n+1,y=(read()+lst-1)%n+1;
//		cout<<x<<" "<<y<<"!!\n";
		if(y+y>=num)cout<<(lst=t1.ans[t1.tt])<<"\n";
		else cout<<(lst=max(t1.get(x,y+y-1),t2.get(x,y+y-1)))<<"\n";
	}
	pc('1',1);
	return 0;
}