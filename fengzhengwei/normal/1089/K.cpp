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
int T;char c[2];
ll sum[4000005];// 
ll add[4000005];// 
void update(int k)
{
	sum[k]=sum[k<<1]+sum[k<<1|1];
	add[k]=max(add[k<<1|1],add[k<<1]+sum[k<<1|1]);
	// 
	//add 
	//add 
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		add[k]=l;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	update(k);
}
void change(int k,int l,int r,int x,int v)
{
	if(l==r)
	{
		sum[k]+=v;
		add[k]+=v;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)change(k<<1,l,mid,x,v);
	else change(k<<1|1,mid+1,r,x,v);
	update(k);
//	cout<<k<<" "<<l<<" "<<r<<" "<<add[k]<<endl;
}
ll ans;
void ask(int k,int l,int r,int x,int y)
{
	if(r<x||y<l)return;
	if(x<=l&&r<=y)
	{
		ans=max(ans+sum[k],add[k]);//
		return ;
	}
	int mid=l+r>>1;
	ask(k<<1,l,mid,x,y);
	ask(k<<1|1,mid+1,r,x,y);
}
int kx[1000005],ky[1000005];
int main(){
//	freopen("a.out","w",stdout);
	T=read();
	build(1,1,1e6);
	for(int i=1;i<=T;i++)
	{
		scanf("%s",c);
		if(c[0]=='+')
		{
			int x,y;
			x=read();y=read();
			kx[i]=x;ky[i]=y;
			change(1,1,1e6,x,y);
		}
		if(c[0]=='-')
		{
			int w=read();
			change(1,1,1e6,kx[w],-ky[w]);
		}
		if(c[0]=='?')
		{
			int x;
			x=read();
			ans=0;
			ask(1,1,1e6,1,x);
			cout<<ans-x<<'\n';
		}
	}
	return 0;
}