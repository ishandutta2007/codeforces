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
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
const int mod=998244353,base=2011111,xx=1e5+5;
ll pw[xx],pws[xx];//pwsbase^0+base^1+base^2+base^3+... 
struct nod
{
	int l,r;
	ll v;
}e[xx<<2];
nod upd(nod a,nod b)
{
	nod c;
	c.l=a.l,c.r=b.r;
	c.v=(a.v+b.v*pw[a.r-a.l+1])%mod;
	return c;
}
int a[xx],cvt[xx<<2];
void build(int k,int l,int r)
{
	if(l==r)return e[k]=(nod){l,l,a[l]},void();
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	e[k]=upd(e[k<<1],e[k<<1|1]);
}
void cv(int k,int a)
{
	cvt[k]=a;
	e[k].v=pws[e[k].r-e[k].l]*a%mod;
}
void pd(int k)
{
	if(cvt[k]!=-1)
	{
		cv(k<<1,cvt[k]);
		cv(k<<1|1,cvt[k]);
		cvt[k]=-1;
	}
}
void cg(int k,int l,int r,int x,int y,int a)
{
	if(x<=l&&r<=y)return cv(k,a);
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)cg(k<<1,l,mid,x,y,a);
	if(mid<y)cg(k<<1|1,mid+1,r,x,y,a);
	e[k]=upd(e[k<<1],e[k<<1|1]);
}
nod ask(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return e[k];
	pd(k);
	int mid=l+r>>1;
	if(y<=mid)return ask(k<<1,l,mid,x,y);
	if(mid<x)return ask(k<<1|1,mid+1,r,x,y);
	return upd(ask(k<<1,l,mid,x,y),ask(k<<1|1,mid+1,r,x,y));
}
signed main(){
	memset(cvt,-1,sizeof(cvt));
	pw[0]=1;pws[0]=1;
	for(int i=1;i<xx;i++)pw[i]=pw[i-1]*base%mod,pws[i]=pw[i]+pws[i-1];
	int n=read(),q=read()+read();
	for(int i=1;i<=n;i++)scanf("%1d",&a[i]);
	build(1,1,n);
	while(q--)
	{
		int op=read();
		if(op==1)
		{
			int l=read(),r=read(),a=read();
			cg(1,1,n,l,r,a);
		}
		else 
		{
			int l=read(),r=read(),s=read(),len=r-l+1;
			if(s==len||ask(1,1,n,l,l+len-s-1).v==ask(1,1,n,r-(len-s)+1,r).v)puts("YES");
			else puts("NO");
		}
	}
	pc('1',1);
	return 0;
}