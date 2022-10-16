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
int a[4000005];
int b[4000005];
int c[4000005];
int sum[4000005];
int vis[4000005];
void change(int k,int l,int r,int x)
{
	sum[k]++;
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid)change(k<<1,l,mid,x);
	else change(k<<1|1,mid+1,r,x);
}
int ask(int k,int l,int r,int x,int y)
{
	if(r<x||y<l)return 0;
	if(x<=l&&r<=y)
	{
		return sum[k];
	}
	int mid=l+r>>1;
	return ask(k<<1,l,mid,x,y)+ask(k<<1|1,mid+1,r,x,y);
}
set<int>s;
int main(){
	n=read();
	s.insert(0);
	s.insert(n+1);
	m=read();
	for(int i=1;i<=n;i++)a[i]=read(),b[a[i]]=i;
	for(int i=1;i<=m;i++)vis[read()]=1;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])s.insert(b[i]);
		else 
		{
			set<int>::iterator it1=s.upper_bound(b[i]),it2=--s.lower_bound(b[i]);
			int l=*it2+1;
			int r=*it1-1;
			ans+=(r-l+1)-ask(1,1,n,l,r);
			change(1,1,n,b[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}