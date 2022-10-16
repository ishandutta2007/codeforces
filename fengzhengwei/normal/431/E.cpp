#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
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
const int xx=1e5+5;
struct node{ll sum1,sum2;int l,r;}e[xx*64];
int n,m,cst;
void ins(int &k,int l,int r,int x,int y)
{
	if(!k)k=++cst;
	e[k].sum1+=y;
	e[k].sum2+=y*x;
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid)ins(e[k].l,l,mid,x,y);
	else ins(e[k].r,mid+1,r,x,y);
}
pair<ll,ll> operator +(pair<ll,ll> a,pair<ll,ll> b){return make_pair(a.first+b.first,a.second+b.second);}
pair<ll,ll> ask(int k,int l,int r,int x)
{
//	cerr<<x<<"\n";
	if(r<=x)return make_pair(e[k].sum1,e[k].sum2);
	int mid=l+r>>1;
	if(x<=mid)return ask(e[k].l,l,mid,x);
	return ask(e[k].l,l,mid,x)+ask(e[k].r,mid+1,r,x);
}
int a[xx];
signed main(){
	n=read(),m=read();
	int root=0;
	for(int i=1;i<=n;i++)ins(root,0,1e9,a[i]=read(),1);
	while(m--)
	{
		int op=read();
		if(op==1)
		{
			int x=read(),y=read();
			ins(root,0,1e9,a[x],-1);
			a[x]=y;
			ins(root,0,1e9,a[x],1);
		}
		else 
		{
			ll v=read();
			long double l=0,r=3e15;
			while(l+0.000001<=r)
			{
				long double mid=(l+r)/2.0;
				pair<ll,ll> s=ask(root,0,1e9,floor(min(1e9l,mid)));
				if(s.first*mid-s.second>=v)r=mid;
				else l=mid;
			}
			cout<<fixed<<setprecision(5)<<l<<"\n";
		}
	}
	return 0;
}