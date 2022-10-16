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
const int xx=1200015;
int mn[xx],last[xx],g[xx],id[xx],pdid[xx],vis[xx],a[xx],b[xx];
int n;
//mntaggpdidtaglast 
//idvis 
void ad(int k,int Mn,int Mnid)
{
	if(vis[k])return ;
	if(g[k]>Mn)//id 
	{
		g[k]=Mn,last[k]=Mnid;
	}
//	cout<<k<<" "<<Mn<<" "<<g[k]<<"!!!\n";
	if(mn[k]>Mn)
	{
		mn[k]=Mn,pdid[k]=Mnid;
	}
}
void pd(int k)
{
	if(mn[k]!=1e9)
	{
		ad(k<<1,mn[k],pdid[k]);
		ad(k<<1|1,mn[k],pdid[k]);
		mn[k]=1e9;
	}
}
void update(int k)
{
	vis[k]=vis[k<<1]&vis[k<<1|1];
	if(vis[k])
	{
		g[k]=1e9;
		return;
	}
	if(vis[k<<1])
	{
		g[k]=g[k<<1|1],id[k]=id[k<<1|1];
		return;
	}
	if(vis[k<<1|1])
	{
		g[k]=g[k<<1],id[k]=id[k<<1];
		return;
	}
	if(g[k<<1]<g[k<<1|1])
	{
		g[k]=g[k<<1],id[k]=id[k<<1];
	}
	else 
	{
		g[k]=g[k<<1|1],id[k]=id[k<<1|1];
	}
}
void build(int k,int l,int r)
{
	g[k]=1e9,mn[k]=1e9,id[k]=l;
	if(l==r)return;
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
int glast(int k,int l,int r,int x)
{
	if(l==r)
		return last[k];
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)return glast(k<<1,l,mid,x);
	return glast(k<<1|1,mid+1,r,x);
}
void cg(int k,int l,int r,int x)
{
	if(l==r)
	{
		g[k]=1e9;
		vis[k]=1;
		return;
	}
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)cg(k<<1,l,mid,x);
	else cg(k<<1|1,mid+1,r,x);
	update(k);
}
void cov(int k,int l,int r,int x,int y,int z,int op)//zop 
{
	if(x<=l&&r<=y)
	{
//		cout<<k<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<" "<<z<<"!!!\n";
		return ad(k,z,op);
	}
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)cov(k<<1,l,mid,x,y,z,op);
	if(mid<y)cov(k<<1|1,mid+1,r,x,y,z,op);
	update(k);
//	cout<<k<<" sss "<<g[k]<<" "<<l<<" "<<r<<"\n";
}
int V[xx],to[xx];
void out(int x)
{
	if(x==n)return;
	out(to[x]);
	cout<<x<<" ";
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		b[i]=read();
	build(1,0,n);
	cov(1,0,n,n,n,0,-1);
//	cout<<id[1]<<" "<<g[1]<<"\n";
//	return 0;
	memset(V,0x3f,sizeof(V));
	for(int i=1;i<=n+1;i++)
	{
		int x=id[1],y=g[1];
		V[x]=y,to[x]=glast(1,0,n,x);
		if(y==1e9)break;
		cg(1,0,n,x);
		// 
		int l=x-a[x+b[x]]+b[x],r=x+b[x];
		cov(1,0,n,l,r,y+1,x);
//		cout<<x<<" sss "<<y<<" "<<l<<" "<<r<<" "<<"\n";
	}
	if(V[0]>=1e9)
	{
		puts("-1");
	}
	else 
	{
		cout<<V[0]<<"\n";
		out(0);
	}
	return 0;
}