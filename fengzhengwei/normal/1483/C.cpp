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
int n,m;
const int xx=3e5+5;
int h[xx];
ll val[xx];
ll f[xx];// 
int to[xx];
int minn[xx<<2];//h 
ll add[xx<<2];// 
int add1[xx<<2];
ll maxs[xx<<2];// (ih)
int vis[xx<<2];//minn 
void build(int k,int l,int r)
{
	minn[k]=1e9;
	maxs[k]=-1e9;
	vis[k]=-1;
	if(l==r)return ;
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void ad1(int k,int v)
{
	add1[k]=v;
	minn[k]=v;
	vis[k]=1;
}
void ad(int k,ll v)
{
	add[k]+=v;
	maxs[k]+=v;
}
void pd(int k)
{
	if(add[k])
	{
		ad(k<<1,add[k]);
		ad(k<<1|1,add[k]);
		add[k]=0;
	}
	if(add1[k])
	{
		ad1(k<<1,add1[k]);
		ad1(k<<1|1,add1[k]);
		add1[k]=0;
	}
}
void update(int k)
{
	if(vis[k<<1]==-1||vis[k<<1|1]==-1)vis[k]=-1;
	else if(minn[k<<1]==minn[k<<1|1])vis[k]=1;
	maxs[k]=max(maxs[k<<1],maxs[k<<1|1]);
	minn[k]=min(minn[k<<1],minn[k<<1|1]);
}
ll ask(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return maxs[k];
	pd(k);
	int mid=l+r>>1;
	ll ans=-1e18;
	if(x<=mid)ans=max(ans,ask(k<<1,l,mid,x,y));
	if(mid<y)ans=max(ans,ask(k<<1|1,mid+1,r,x,y));
	update(k);
	return ans;
}
int find(int k,int l,int r,int x,int y,int z)//xy 
{
//	if(z==1)cout<<k<<" s "<<l<<" "<<r<<" "<<x<<" "<<y<<" "<<minn[k]<<"\n";
	if(x<=l&&r<=y&&minn[k]>=z)return l;
	if(l==r)return r+1;
	int mid=l+r>>1;
	pd(k);
	if(y<=mid)return find(k<<1,l,mid,x,y,z);
	if(x>mid)return find(k<<1|1,mid+1,r,x,y,z);
	int s=find(k<<1|1,mid+1,r,x,y,z);
	if(s!=mid+1)return s;
	return find(k<<1,l,mid,x,y,z);
}
void change(int k,int l,int r,int x,int y,int z)//minnzz 
{
	if(x>y)return;
	if(x<=l&&r<=y)
	{
		if(vis[k]==1)
		{
			ad(k,val[to[z]]-val[to[minn[k]]]);
			ad1(k,z);
			return;
		}
	}
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)change(k<<1,l,mid,x,y,z);
	if(mid<y)change(k<<1|1,mid+1,r,x,y,z);
	update(k);
}
void change1(int k,int l,int r,int x,ll y,int z)// (yz)
{
	if(l==r)
	{
		maxs[k]=y;
		minn[k]=z;
		vis[k]=1;
		return ;
	}
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)change1(k<<1,l,mid,x,y,z);
	else change1(k<<1|1,mid+1,r,x,y,z);
	update(k);
//	cout<<k<<" "<<l<<" "<<r<<" "<<minn[k]<<"\n";
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)h[i]=read(),to[h[i]]=i;
//	to[n+1]=n+1;//0n+1 
	for(int i=1;i<=n;i++)val[i]=read();
	build(1,0,n);//0
	change1(1,0,n,0,val[1],h[1]);
	for(int i=1;i<=n;i++)
	{
		f[i]=ask(1,0,n,0,i-1);
//		cout<<i<<" "<<f[i]<<"\n";
		if(i==n)break;
		int s=find(1,0,n,0,i-1,h[i+1]);
//		cout<<i<<" "<<f[i]<<" "<<h[i+1]<<" "<<minn[1]<<"\n";
		change(1,0,n,s,i-1,h[i+1]);
		change1(1,0,n,i,f[i]+val[i+1],h[i+1]);
	}
	cout<<f[n]<<"\n";
	return 0;
}