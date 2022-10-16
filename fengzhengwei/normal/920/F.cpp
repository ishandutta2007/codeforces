#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e6+5;
int prim[xx];
int f[xx];
int vis[xx];
void pre()
{
	f[1]=1;
	int cnt=0;
	for(int i=2;i<=xx;i++)
	{
		if(!vis[i])
		{
			prim[++cnt]=i;
			f[i]=2;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(prim[j]*i>xx)break;
			vis[prim[j]*i]=1;
			if(i%prim[j]==0)
			{
				f[i*prim[j]] = f[i]*2-f[i/prim[j]];
				break;
			}
			f[i*prim[j]]=f[i]*2;
		}
	}
}
ll a[xx];
ll sum[xx<<2];
int bs[xx<<2];
void build(int k,int l,int r)
{
	if(l==r)
	{
		sum[k]=a[l];
		if(sum[k]==1||sum[k]==2)bs[k]=1;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	sum[k]=sum[k<<1]+sum[k<<1|1];
	if(bs[k<<1]&&bs[k<<1|1])bs[k]=1;
}
void change(int k,int l,int r,int x,int y)
{
	if(bs[k])return;
	if(l==r)
	{
		sum[k]=f[sum[k]];
		if(sum[k]==1||sum[k]==2)bs[k]=1;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)change(k<<1,l,mid,x,y);
	if(y>mid)change(k<<1|1,mid+1,r,x,y);
	sum[k]=sum[k<<1]+sum[k<<1|1];
	if(bs[k<<1]&&bs[k<<1|1])bs[k]=1;
}
ll ask(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return sum[k];
	int mid=l+r>>1;
	return ((x<=mid)?ask(k<<1,l,mid,x,y):0)+((mid<y)?ask(k<<1|1,mid+1,r,x,y):0);
}

int main(){
	pre();
	int n,m;
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int op=read();
		int l,r;
		l=read();
		r=read();
		if(op==1)change(1,1,n,l,r);
		else cout<<ask(1,1,n,l,r)<<"\n";
	}
	return 0;
}