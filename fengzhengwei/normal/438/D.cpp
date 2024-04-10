#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
const int xx=1e5+5;
int a[xx];
ll maxx[xx<<2];
ll sum[xx<<2];
void build(int k,int l,int r)
{
	if(l==r)
	{
		sum[k]=maxx[k]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	sum[k]=sum[k<<1]+sum[k<<1|1];
	maxx[k]=max(maxx[k<<1],maxx[k<<1|1]);
}
ll ask(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return sum[k];
	int mid=l+r>>1;
	return ((x<=mid)?ask(k<<1,l,mid,x,y):0)+((mid<y)?ask(k<<1|1,mid+1,r,x,y):0);
}
void change(int k,int l,int r,int x,int y,int z)
{
	if(maxx[k]<z)return;
	if(l==r)
	{
		sum[k]%=z;
		maxx[k]=sum[k];
		return ;
	}
	int mid=l+r>>1;
	(x<=mid)?change(k<<1,l,mid,x,y,z):void();
	(mid<y)?change(k<<1|1,mid+1,r,x,y,z):void();
	sum[k]=sum[k<<1]+sum[k<<1|1];
	maxx[k]=max(maxx[k<<1],maxx[k<<1|1]);
}
void change(int k,int l,int r,int x,int z)
{
	if(l==r)
	{
		sum[k]=z;
		maxx[k]=sum[k];
		return ;
	}
	int mid=l+r>>1;
	(x<=mid)?change(k<<1,l,mid,x,z):change(k<<1|1,mid+1,r,x,z);
	sum[k]=sum[k<<1]+sum[k<<1|1];
	maxx[k]=max(maxx[k<<1],maxx[k<<1|1]);
}
void print(int k,int l,int r)
{
	if(l==r)
	{
		cout<<sum[k]<<" ";
		return;
	}
	int mid=l+r>>1;
	print(k<<1,l,mid);
	print(k<<1|1,mid+1,r);
}
int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int op=read();
		if(op==1)
		{
			int l,r;
			l=read();
			r=read();
			cout<<ask(1,1,n,l,r)<<"\n";
		}
		else if(op==2)
		{
			int l,r;
			l=read();
			r=read();
			change(1,1,n,l,r,read());
		}
		else 
		{
			int l;
			l=read();
			change(1,1,n,l,read());
		}
//		print(1,1,n);
//		cout<<"\n";
	}
	return 0;
}