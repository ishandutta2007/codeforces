#include<bits/stdc++.h>
#define ll long long 
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;};return *s++;}
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
	wt(x),pc(op,0);
}
const int xx=4e5+5;
int n,q;
struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
int F[xx][21],f[xx],dep[xx];
void dfs(int x,int y)
{
	dep[x]=dep[y]+1,F[x][0]=y,f[x]=y;
	for(int i=1;i<=20;i++)F[x][i]=F[F[x][i-1]][i-1];
	for(int i=h[x];i;i=e[i].next)
		if(e[i].to!=y)dfs(e[i].to,x);
}
int lg[xx];
int lca(int x,int y)
{
//	cout<<x<<" "<<y<<" ";
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]!=dep[y])x=F[x][lg[dep[x]-dep[y]]];
	if(x==y)return x;
	for(int i=20;i>=0;i--)(F[x][i]^F[y][i])?(x=F[x][i],y=F[y][i]):0;
//	cout<<F[x][0]<<"^^^\n";
	return F[x][0];
}
int lb(int x){return x&-x;}
int sum[xx];
//splayrootval 
void ad(int x,int y){x++;for(;x<xx;x+=lb(x))sum[x]+=y;}
int ask(int x){x++;int ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
int c[xx][2],siz[xx],val[xx],rev[xx];
bool nroot(int x){return c[f[x]][0]==x||c[f[x]][1]==x;}
void upd(int x){siz[x]=siz[c[x][0]]+siz[c[x][1]]+1;}
void rv(int x){if(x)swap(c[x][0],c[x][1]),rev[x]^=1;}
void pd(int x){if(rev[x])rv(c[x][0]),rv(c[x][1]),rev[x]=0;}
void pds(int x){if(nroot(x))pds(f[x]);pd(x);}
void rotate(int x)
{
	int y=f[x],z=f[y],s=c[y][1]==x;
	c[y][s]=c[x][!s],f[c[x][!s]]=y;
	f[x]=z;if(nroot(y))c[z][c[z][1]==y]=x;
	f[c[x][!s]=y]=x,upd(y);
}
int fr(int x)
{
	if(nroot(x))return fr(f[x]);
	return x;
}
void splay(int x)
{
//	cout<<x<<"#\n";
	pds(x);
	int V=val[fr(x)];
	while(nroot(x))
	{
//	cout<<x<<"$$\n";
		int y=f[x],z=f[y];
		if(nroot(y))
		{
			if((c[z][1]==y)==(c[y][1]==x))rotate(y);
			else rotate(x);
		}
		rotate(x);
	}
	upd(x);
	val[x]=V;
}
void access(int x,int z)
{
	int y;
	for(y=0;x;x=f[y=x])
	{
		splay(x);
		if(c[x][1])val[c[x][1]]=val[x];
		c[x][1]=0,upd(x);
		ad(val[x],-siz[x]);
		c[x][1]=y;
		upd(x);
	}
	x=y;
	splay(x),val[x]=z; 
	ad(val[x],siz[x]);
}
int dis(int x,int y){return dep[x]+dep[y]-2*dep[lca(x,y)];}//-1
int rt;
int get(int x)
{
	splay(x);
	return ask(val[x])-siz[c[x][0]];
//	dis(x,rt);
}
signed main(){
	lg[0]=-1;
	for(int i=1;i<xx;i++)lg[i]=lg[i-1]+(i==lb(i));
	n=read(),q=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	ad(0,n),dfs(1,0);
	for(int i=1;i<=n;i++)siz[i]=1;
	int tt=0;
	rt=1;
//	puts("asdas");
//	for(int i=1;i<=n;i++)cout<<i<<" "<<f[i]<<"%%\n";
	for(int i=1;i<=n;i++)
	{
//		cout<<i<<"$%$\n";
		access(i,tt),splay(i),rv(i),++tt,rt=i;
	}
	while(q--)
	{
		char s[25];
		scanf("%s",s);
		if(s[0]=='w')
		{
			int x=read();
			splay(x);
//			for(int i=1;i<=n;i++)cout<<i<<" "<<ask(i)<<"%^%^\n";
//			cout<<rt<<" "<<dis(x,rt)<<"$$\n";
//			cout<<x<<" "<<val[x]<<" "<<siz[x]<<"$$\n";
			cout<<get(x)<<"\n";
		}
		if(s[0]=='c')
		{
			int x=read(),y=read();
			if(get(x)<get(y))cout<<x<<"\n";
			else cout<<y<<"\n";
		}
		if(s[0]=='u')
		{
			int x=read();
			access(x,tt),splay(x),rv(x),++tt,rt=x;
		}
	}
	pc('1',1);
	return 0;
}