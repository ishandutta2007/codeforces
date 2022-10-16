#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc/
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
const int xx=5e5+5;
int n,q;
struct nod
{
	int l,r,k;
	bool operator<(const nod&w)const{return r<w.r;}
}e[xx];
ll sa[xx],sc[xx],sb[xx];//c 
namespace S
{
	struct node{ll ml,mr,mx;}e[xx<<2];
	node upd(const node&a,const node&b)
	{
		node c;c.mx=max(a.mx,b.mx);
		c.ml=max(a.ml,b.ml);
		c.mr=max(a.mr,b.mr);
		c.mx=max(c.mx,a.ml+b.mr);
		return c;
	}
	void one(int k,int l,int r,int x,node v)
	{
		if(x>n)return;
		if(l==r)return e[k]=v,void();
		int mid=l+r>>1;
		if(x<=mid)one(k<<1,l,mid,x,v);
		else one(k<<1|1,mid+1,r,x,v);
		e[k]=upd(e[k<<1],e[k<<1|1]);
	}
	node ask(int k,int l,int r,int x,int y)
	{
		if(x<=l&&r<=y)return e[k];
		int mid=l+r>>1;
		if(y<=mid)return ask(k<<1,l,mid,x,y);
		if(mid<x)return ask(k<<1|1,mid+1,r,x,y);
		return upd(ask(k<<1,l,mid,x,y),ask(k<<1|1,mid+1,r,x,y));
	}
}
ll f[xx],g[xx];
ll a[xx],b[xx],c[xx];
int main(){
	n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read(),sa[i]=sa[i-1]+a[i];
	for(int i=1;i<=n;i++)b[i]=read(),sb[i]=sb[i-1]+b[i];
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=n;i>=1;i--)sc[i]=sc[i+1]+c[i];
	for(int i=1;i<=q;i++)
		e[i].l=read(),e[i].r=read(),e[i].k=read();
	ll ans=-1e18;
	for(int i=1;i<=n;i++)
		S::one(1,1,n,i,{sa[i]-sb[i-1],sc[i]+sb[i],sa[i]-sb[i-1]+sc[i]+sb[i]});
	sort(e+1,e+q+1);
	for(int i=1;i<=q;i++)
		ans=max(ans,S::ask(1,1,n,e[i].l,e[i].r).mx-e[i].k);
//	cout<<ans<<"!!\n";
	memset(g,-0x3f,sizeof(g));
	for(int i=1;i<=q;i++)
	{
		f[i]=S::ask(1,1,n,e[i].l,e[i].r).ml+sb[e[i].r]-e[i].k;
//		cout<<i<<" "<<e[i].l<<" "<<e[i].r<<" "<<e[i].k<<" "<<f[i]<<"!!\n";
		int R=e[i].r;
		g[R]=max(g[R],f[i]);
		S::one(1,1,n,R+1,{max(sa[R+1]-sb[R],g[R]-sb[R]),sc[R+1]+sb[R+1],max(sa[R+1]-sb[R],g[R]-sb[R])+sc[R+1]+sb[R+1]});
	}
	for(int i=1;i<=q;i++)
		ans=max(ans,S::ask(1,1,n,e[i].l,e[i].r).mx-e[i].k);
	cout<<ans<<"\n";
	
	pc('1',1);
	return 0;
}