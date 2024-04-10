#include<bits/stdc++.h>
#define ll long long
#define dd double
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
const int xx=500005;
struct one{int v,id;};
struct two{int v,idl,idr;bool operator==(const two&w)const{return v==w.v&&idl==w.idl&&idr==w.idr;};};
// 
one upd(const one &a,const one &b){return a.v<b.v?a:b;}
two upd(const two &a,const two &b){return a.v<b.v?a:b;}
struct nod
{
	one l,r,L,R;
	two lr,RL,rl;
	int mn;
	//a 
	//b 
	//lrlr 
	//L[l,i)
	//R[i,r] 
	//rl 
}e[xx<<2];
two Upd(const one &a,const one &b){return {a.v+b.v,a.id,b.id};}
//i~i+1 
nod upd(nod a,nod b)
{
	nod c;
	c.mn=min(a.mn,b.mn);
	//lrRL 
	c.lr=upd(a.lr,b.lr);c.rl=upd(a.rl,b.rl);
	c.lr=upd(Upd(a.l,b.r),c.lr);
	c.rl=upd(Upd(a.r,b.l),c.rl);
	c.l=upd(a.l,b.l);c.r=upd(a.r,b.r);
	if(a.mn>b.mn)c.L=upd(a.l,b.L);
	else c.L=a.L;
	if(a.mn<b.mn)c.R=upd(a.R,b.r);
	else c.R=b.R;
	if(a.mn==b.mn)c.RL=upd(a.RL,b.RL),c.RL=upd(c.RL,Upd(a.R,b.L));
	if(a.mn<b.mn)c.RL=upd(a.RL,b.rl),c.RL=upd(c.RL,Upd(a.R,b.l));
	if(a.mn>b.mn)c.RL=upd(a.rl,b.RL),c.RL=upd(c.RL,Upd(a.r,b.L));
	return c;
}
int adt[xx<<2];
void ad(int k,int z){adt[k]+=z,e[k].mn+=z;}
void pd(int k){if(adt[k])ad(k<<1,adt[k]),ad(k<<1|1,adt[k]),adt[k]=0;}
void cg(int k,int l,int r,int x,int y,int z)
{
	if(x>y)return;
	if(x<=l&&r<=y)return ad(k,z);
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)cg(k<<1,l,mid,x,y,z);
	if(mid<y)cg(k<<1|1,mid+1,r,x,y,z);
	e[k]=upd(e[k<<1],e[k<<1|1]);
}
int n,k,a[xx],b[xx];
const int inf=1e9+1;
void re(int k,int l)//l 
{e[k]={{a[l],l},{b[l],l},{a[l],l},{inf,l},{a[l]+b[l],l,l},{inf+inf,l,l},{inf+inf,l,l},adt[k]};}
void build(int k,int l,int r)
{
	if(l==r)return re(k,l);
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	e[k]=upd(e[k<<1],e[k<<1|1]);
}
void C(int k,int l,int r,int x)
{
	if(l==r)return re(k,l);
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)C(k<<1,l,mid,x);
	else C(k<<1|1,mid+1,r,x);
	e[k]=upd(e[k<<1],e[k<<1|1]);
}
signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	build(1,1,n);
	ll ans=0;
	for(int i=1;i<=k;i++)
	{
		two now;
		now=upd(e[1].lr,e[1].mn==0?e[1].RL:e[1].rl);
		ans+=now.v;
		if(now==e[1].lr)a[now.idl]=inf,b[now.idr]=inf,cg(1,1,n,now.idl,now.idr-1,1);
		else a[now.idr]=inf,b[now.idl]=inf,cg(1,1,n,now.idl,now.idr-1,-1);
		C(1,1,n,now.idl);
		C(1,1,n,now.idr);
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}