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
struct node
{
	int sum,l,r;
}e[8000005];
int cst;
void insert(int &x,int y,int l,int r,int v)
{
	x=++cst;
	e[x]=e[y];
	e[x].sum++;
	if(l==r)return;
	int mid=l+r>>1;
	if(v<=mid)insert(e[x].l,e[y].l,l,mid,v);
	else insert(e[x].r,e[y].r,mid+1,r,v);
}
int root[1000005];
ll js(ll x)
{
	return (x*(x-1))/2;
}
ll ask(int x1,int y1,int l,int r,int x,int y)
{
	if(!y1&&!x1)return 0;
	if(r<x||y<l)return 0;
	if(x<=l&&r<=y)return e[y1].sum-e[x1].sum;
	int mid=l+r>>1;
	return ask(e[x1].l,e[y1].l,l,mid,x,y)+ask(e[x1].r,e[y1].r,mid+1,r,x,y);
}
int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		int s=read();
		insert(root[i],root[i-1],1,n,s);
	}
//	int q=read();
	while(m--)
	{
		int a,b,c,d;
		a=read();
		b=read();
		c=read();
		d=read();
		ll nowres=js(n)-js(a-1)-js(b-1)-js(n-c)-js(n-d);
		nowres+=js(ask(root[0],root[a-1],1,n,1,b-1));
		nowres+=js(ask(root[c],root[n],1,n,1,b-1));
		nowres+=js(ask(root[0],root[a-1],1,n,d+1,n));
		nowres+=js(ask(root[c],root[n],1,n,d+1,n));
		cout<<nowres<<"\n";
	}
	return 0;
}