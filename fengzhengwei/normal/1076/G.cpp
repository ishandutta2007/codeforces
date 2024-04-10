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
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=2e5+5;
int n,m,q,rev[xx<<2];
struct nod
{
	int to[(1<<5)];
	nod operator +(const nod&b)const
	{
		nod c;
		for(int i=0;i<(1<<m);i++)c.to[i]=to[b.to[i]];
		return c;
	}
};
nod f[xx<<2][2];//01 
int a[xx];
void build(int k,int l,int r)
{
	if(l==r)
	{
		//10 
		for(int i=0;i<(1<<m);i++)
		{
			f[k][0].to[i]=(((a[l]==0)|(i!=(1<<m)-1))<<(m-1))|(i>>1);
			f[k][1].to[i]=(((a[l]==1)|(i!=(1<<m)-1))<<(m-1))|(i>>1);
		}
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid),build(k<<1|1,mid+1,r);
	f[k][0]=f[k<<1][0]+f[k<<1|1][0];
	f[k][1]=f[k<<1][1]+f[k<<1|1][1];
}
void rv(int k){if(k)swap(f[k][0],f[k][1]),rev[k]^=1;}
void pd(int k){if(rev[k])rv(k<<1),rv(k<<1|1),rev[k]=0;}
void cg(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return rv(k);
	int mid=l+r>>1;pd(k);
	if(x<=mid)cg(k<<1,l,mid,x,y);
	if(mid<y)cg(k<<1|1,mid+1,r,x,y);
	f[k][0]=f[k<<1][0]+f[k<<1|1][0];
	f[k][1]=f[k<<1][1]+f[k<<1|1][1];
}
nod ask(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return f[k][0];
	int mid=l+r>>1;pd(k);
	if(y<=mid)return ask(k<<1,l,mid,x,y);
	if(mid<x)return ask(k<<1|1,mid+1,r,x,y);
	return ask(k<<1,l,mid,x,y)+ask(k<<1|1,mid+1,r,x,y);
}
int main(){
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read()&1;
	build(1,1,n);
	while(q--)
	{
		int op=read();
		if(op&1)
		{
			int l=read(),r=read();
			if(read()&1)cg(1,1,n,l,r);
		}
		else 
		{
			int l=read(),r=read();
			cout<<(((ask(1,1,n,l,r).to[(1<<m)-1]>>(m-1))&1)?1:2)<<"\n";
		}
	}
	pc('1',1);
	return 0;
}