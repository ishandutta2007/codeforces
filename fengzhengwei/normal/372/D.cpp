#include<bits/stdc++.h>
#define ll long long 
#define dd double
#define LL __int128
#define ull unsigned ll
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
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
int n,m;
struct nod
{
	int next,to;
}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
int dfx[xx],dep[xx],siz[xx],son[xx],top[xx],f[xx];
void dfs(int x,int y)
{
	int mx=-1;
	f[x]=y,dep[x]=dep[y]+1,siz[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x),siz[x]+=siz[e[i].to];
		if(siz[e[i].to]>mx)mx=siz[e[i].to],son[x]=e[i].to;
	}
}
int cst;
void dfss(int x,int y)
{
	top[x]=y,dfx[x]=++cst;
	if(!son[x])return ;
	dfss(son[x],y);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==f[x]||e[i].to==son[x])continue;
		dfss(e[i].to,e[i].to);
	}
}
namespace seg
{
	struct info{int mn,sum;}e[xx<<2];
	info upd(const info&A,const info&B){return A.mn<B.mn?A:B.mn<A.mn?B:(info){A.mn,A.sum+B.sum};}
	int adt[xx<<2];
	void ad(int k,int z){adt[k]+=z,e[k].mn+=z;}
	void pd(int k){if(adt[k])ad(k<<1,adt[k]),ad(k<<1|1,adt[k]),adt[k]=0;}
	info ask(int k,int l,int r,int x,int y)
	{
		if(x<=l&&r<=y)return e[k];
		pd(k);int mid=l+r>>1;
		if(y<=mid)return ask(k<<1,l,mid,x,y);
		if(mid<x)return ask(k<<1|1,mid+1,r,x,y);
		return upd(ask(k<<1,l,mid,x,y),ask(k<<1|1,mid+1,r,x,y));
	}
	void cov(int k,int l,int r,int x,int y,int z)
	{
		if(x<=l&&r<=y)return ad(k,z);
		pd(k);int mid=l+r>>1;
		if(x<=mid)cov(k<<1,l,mid,x,y,z);
		if(mid<y)cov(k<<1|1,mid+1,r,x,y,z);
		e[k]=upd(e[k<<1],e[k<<1|1]);
	}
	void build(int k,int l,int r)
	{
		e[k].sum=r-l+1;
		if(l==r)return;
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
	}
	int get(){return e[1].mn==0?n-e[1].sum:n;}
	void jump(int x,int y,int z)
	{
		while(top[x]!=top[y])
		{
//			cerr<<x<<" "<<y<<"%%\n";
			if(dep[top[x]]<dep[top[y]])swap(x,y);
			cov(1,1,n,dfx[top[x]],dfx[x],z);
			x=f[top[x]];
		}
		if(dep[x]<dep[y])swap(x,y);
		cov(1,1,n,dfx[y],dfx[x],z);
	}
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	dfs(1,0),dfss(1,1);
	seg::build(1,1,n);
	int ans=0,rp=0;
	for(int i=1;i<=n;i++)
	{
		rp=max(rp,i);
		while(seg::get()<=m)
		{
//			cerr<<rp<<"$\n";
			ans=max(ans,rp-i+1);
			if(rp+1<=n)seg::jump(rp,rp+1,1),++rp; 
			else break;
		}
//		cerr<<i<<" "<<rp<<" "<<"$$\n";
		if(rp!=i)seg::jump(i,i+1,-1);
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}