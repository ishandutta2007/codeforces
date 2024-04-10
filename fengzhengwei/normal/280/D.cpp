#include<bits/stdc++.h>
using namespace std;
int read(){
	char c;int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int lmax[400005],rmax[400005],lmin[400005],rmin[400005],maxx[400005],minn[400005],lmaxid[400005],rmaxid[400005],lminid[400005],rminid[400005],maxxidl[400005],maxxidr[400005],minnidl[400005],minnidr[400005],sum[400005],rev[400005];
int n,a[400005];
void update(int k,int l,int r)
{
	sum[k]=sum[k<<1]+sum[k<<1|1];
	lmax[k]=lmax[k<<1];
	lmaxid[k]=lmaxid[k<<1];
	if(lmax[k<<1|1]+sum[k<<1]>lmax[k]){
		lmax[k]=lmax[k<<1|1]+sum[k<<1];
		lmaxid[k]=lmaxid[k<<1|1];
	}
	lmin[k]=lmin[k<<1];
	lminid[k]=lminid[k<<1];
	if(lmin[k<<1|1]+sum[k<<1]<lmin[k]){
		lmin[k]=lmin[k<<1|1]+sum[k<<1];
		lminid[k]=lminid[k<<1|1];
	}
	rmax[k]=rmax[k<<1|1];
	rmaxid[k]=rmaxid[k<<1|1];
	if(rmax[k<<1]+sum[k<<1|1]>rmax[k])
	{
		rmax[k]=rmax[k<<1]+sum[k<<1|1];
		rmaxid[k]=rmaxid[k<<1];
	}
	rmin[k]=rmin[k<<1|1];
	rminid[k]=rminid[k<<1|1];
	if(rmin[k<<1]+sum[k<<1|1]<rmin[k])
	{
		rmin[k]=rmin[k<<1]+sum[k<<1|1];
		rminid[k]=rminid[k<<1];
	}
	if(maxx[k<<1]>maxx[k<<1|1])
	{
		maxx[k]=maxx[k<<1];
		maxxidl[k]=maxxidl[k<<1];
		maxxidr[k]=maxxidr[k<<1];
	}
	else
	{
		maxx[k]=maxx[k<<1|1];
		maxxidl[k]=maxxidl[k<<1|1];
		maxxidr[k]=maxxidr[k<<1|1];
	}
	if(rmax[k<<1]+lmax[k<<1|1]>maxx[k])
	{
		maxx[k]=rmax[k<<1]+lmax[k<<1|1];
		maxxidl[k]=rmaxid[k<<1];
		maxxidr[k]=lmaxid[k<<1|1];
	}
	if(minn[k<<1]<minn[k<<1|1])
	{
		minn[k]=minn[k<<1];
		minnidl[k]=minnidl[k<<1];
		minnidr[k]=minnidr[k<<1];
	}
	else
	{
		minn[k]=minn[k<<1|1];
		minnidl[k]=minnidl[k<<1|1];
		minnidr[k]=minnidr[k<<1|1];
	}
	if(rmin[k<<1]+lmin[k<<1|1]<minn[k])
	{
		minn[k]=rmin[k<<1]+lmin[k<<1|1];
		minnidl[k]=rminid[k<<1];
		minnidr[k]=lminid[k<<1|1];
	}
}
void rv(int k,int l,int r)
{
	rev[k]^=1;
	sum[k]=-sum[k];
	swap(lmax[k],lmin[k]);
	lmax[k]=-lmax[k];
	lmin[k]=-lmin[k];
	swap(rmax[k],rmin[k]);
	rmax[k]=-rmax[k];
	rmin[k]=-rmin[k];
	swap(lmaxid[k],lminid[k]);
	swap(rmaxid[k],rminid[k]);
	swap(maxx[k],minn[k]);
	maxx[k]=-maxx[k];
	minn[k]=-minn[k];
	swap(maxxidl[k],minnidl[k]);
	swap(maxxidr[k],minnidr[k]);
}
void pushdown(int k,int l,int r)
{
	if(rev[k]){
		rev[k]=0;
		int mid=l+r>>1;
		rv(k<<1,l,mid);
		rv(k<<1|1,mid+1,r);
	}
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		sum[k]=a[l];
		if(a[l]>0)
		{
			lmax[k]=a[l];
			lmaxid[k]=l;
			rmax[k]=a[l];
			rmaxid[k]=l;
			maxx[k]=a[l];
			maxxidl[k]=maxxidr[k]=l;
			lmin[k]=rmin[k]=minn[k]=0;
			lminid[k]=l-1;
			rminid[k]=l+1;
			minnidl[k]=l+1;
			minnidr[k]=l-1;
		}
		else 
		{
			lmin[k]=a[l];
			lminid[k]=l;
			rmin[k]=a[l];
			rminid[k]=l;
			minn[k]=a[l];
			minnidl[k]=minnidr[k]=l;
			lmax[k]=rmax[k]=maxx[k]=0;
			lmaxid[k]=l-1;
			rmaxid[k]=l+1;
			maxxidl[k]=l+1;
			maxxidr[k]=l-1;
		}
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	update(k,l,r);
//	cout<<l<<" "<<r<<" "<<maxxidl[k]<<" "<<maxxidr[k]<<endl;
}
void change(int k,int l,int r,int x,int v)
{
	if(l==r)
	{
		sum[k]=v;
		if(v>0)
		{
			lmax[k]=v;
			lmaxid[k]=l;
			rmax[k]=v;
			rmaxid[k]=l;
			maxx[k]=v;
			maxxidl[k]=maxxidr[k]=l;
			lmin[k]=rmin[k]=minn[k]=0;
			lminid[k]=l-1;
			rminid[k]=l+1;
			minnidl[k]=l+1;
			minnidr[k]=l-1;
		}
		else 
		{
			lmin[k]=v;
			lminid[k]=l;
			rmin[k]=v;
			rminid[k]=l;
			minn[k]=v;
			minnidl[k]=minnidr[k]=l;
			lmax[k]=rmax[k]=maxx[k]=0;
			lmaxid[k]=l-1;
			rmaxid[k]=l+1;
			maxxidl[k]=l+1;
			maxxidr[k]=l-1;
		}
		return;
	}
	pushdown(k,l,r);
	int mid=l+r>>1;
	if(x<=mid)change(k<<1,l,mid,x,v);
	else change(k<<1|1,mid+1,r,x,v);
	update(k,l,r);
}
void changef(int k,int l,int r,int x,int y)
{
	if(r<x||y<l)return;
	if(x<=l&&r<=y)
	{
		rv(k,l,r);
		return;
	}
	pushdown(k,l,r);
	int mid=l+r>>1;
	changef(k<<1,l,mid,x,y);
	changef(k<<1|1,mid+1,r,x,y);
	update(k,l,r);
}
struct node
{
	int maxx;
	int maxxidl;
	int maxxidr;
	int lmax;
	int lmaxid;
	int rmax;
	int rmaxid;
	int sum;
};
node ask(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)
	{
//		cout<<k<<" "<<l<<' '<<r<<" "<<maxx[k]<<" "<<maxxidl[k]<<" "<<maxxidr[k]<<" "<<lmax[k]<<" "<<lmaxid[k]<<" "<<rmax[k]<<" "<<rmaxid[k]<<" "<<sum[k]<<endl;
		return (node){maxx[k],maxxidl[k],maxxidr[k],lmax[k],lmaxid[k],rmax[k],rmaxid[k],sum[k]};
	}
	pushdown(k,l,r);
	int mid=l+r>>1;
	if(l<=x&&y<=mid)return ask(k<<1,l,mid,x,y);
	if(mid+1<=x&&y<=r)return ask(k<<1|1,mid+1,r,x,y);
	node a,b;
	a=ask(k<<1,l,mid,x,mid);
	b=ask(k<<1|1,mid+1,r,mid+1,y);
	node c;
	c.sum=a.sum+b.sum;
	c.lmax=a.lmax;
	c.lmaxid=a.lmaxid;
	if(a.sum+b.lmax>c.lmax)c.lmax=a.sum+b.lmax,c.lmaxid=b.lmaxid;
	c.rmax=b.rmax;
	c.rmaxid=b.rmaxid;
	if(b.sum+a.rmax>c.rmax)c.rmax=b.sum+a.rmax,c.rmaxid=a.rmaxid;
	if(a.maxx>b.maxx)
	{
		c.maxx=a.maxx;
		c.maxxidl=a.maxxidl;
		c.maxxidr=a.maxxidr;
	}
	else 
	{
		c.maxx=b.maxx;
		c.maxxidl=b.maxxidl;
		c.maxxidr=b.maxxidr;
	}
	if(b.lmax+a.rmax>c.maxx)
	{
		c.maxx=b.lmax+a.rmax;
		c.maxxidl=a.rmaxid;
		c.maxxidr=b.lmaxid;
	}
	return c;
}
int ll[105];
int rr[105];
signed main(){
//	freopen("a.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	build(1,1,n);
//	cout<<maxx[1]<<endl;
//	cout<<maxxidl[1]<<" "<<maxxidr[1]<<endl;
	int m=read();
	for(int i=1;i<=m;i++)
	{
		int op=read();
		if(op==0)
		{
			int o=read();
			int p=read();
			change(1,1,n,o,p);
		}
		else 
		{
			int l,r,k;
			l=read();
			r=read();
			k=read();
			int ans=0;
			for(int ii=1;ii<=k;ii++)
			{
				node p=ask(1,1,n,l,r);
				if(p.maxx>=0)
				{
					ans+=p.maxx;
					ll[ii]=p.maxxidl;
					rr[ii]=p.maxxidr;
//					cout<<ll[ii]<<" "<<rr[ii]<<endl;
					changef(1,1,n,ll[ii],rr[ii]);
				}
				else ll[ii]=rr[ii]=0;
			}
			printf("%d\n",ans);
			for(int ii=1;ii<=k;ii++)
			{
				changef(1,1,n,ll[ii],rr[ii]);
			}
		}
	}
	return 0;
}