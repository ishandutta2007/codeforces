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
int n;
const int xx=150005;
struct node
{
	int next,to;
}e[xx<<1];
int cnt;
int h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
struct nod
{
	ll k,b,vis;
	int l,r;
}w[xx<<6];
int cst;
ll res(ll x,ll k,ll b)
{
	return k*x+b;
}
void add(int &k,ll l,ll r,ll x,ll y)
{
//	cout<<k<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<"\n";
	if(!k)k=++cst,w[k].vis=1,w[k].l=w[k].r=0;
	if(w[k].vis)return w[k].vis=0,w[k].k=x,w[k].b=y,void();
	ll mid=l+r>>1;
	if(w[k].k<=x)
	{
		if(res(mid,w[k].k,w[k].b)>=res(mid,x,y))((l!=r)?add(w[k].r,mid+1,r,x,y):void());
		else ((l!=r)?add(w[k].l,l,mid,w[k].k,w[k].b):void()),w[k].k=x,w[k].b=y;
	}
	else 
	{
		if(res(mid,w[k].k,w[k].b)>=res(mid,x,y))((l!=r)?add(w[k].l,l,mid,x,y):void());
		else ((l!=r)?add(w[k].r,mid+1,r,w[k].k,w[k].b):void()),w[k].k=x,w[k].b=y;
	}
}
int vis[xx];
int cur;
int size[xx];
int sum;
int root;
void find(int x,int y)
{
	size[x]=1;
	int maxx=-1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y||vis[e[i].to])continue;
		find(e[i].to,x);
		size[x]+=size[e[i].to];
		maxx=max(maxx,size[e[i].to]);
	}
	maxx=max(maxx,sum-size[x]);
	if(!cur||maxx<=sum/2)cur=x;
}
ll a[xx];
ll ans;
void ask(int k,ll l,ll r,ll x)
{
	if(!k)return;
	if(w[k].vis==0)ans=max(ans,res(x,w[k].k,w[k].b));
	int mid=l+r>>1;
	if(x<=mid)ask(w[k].l,l,mid,x);
	else ask(w[k].r,mid+1,r,x);
}
ll ress;
void getans(int x,int y,ll sum,ll v2,int dep)//sum 
{
	sum+=a[x];
	v2+=a[x]*dep;
//	cout<<x<<" ss "<<y<<" "<<sum<<" "<<v2<<" "<<dep<<"\n";
	ans=0;
	ask(root,1,1e13,sum);
	ress=max(ress,ans+v2);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y||vis[e[i].to])continue;
		getans(e[i].to,x,sum,v2,dep+1);
	}
}
void getadd(int x,int y,ll sum,ll v1,int dep)// 
{
	sum+=a[x];
	v1+=sum;
//	cout<<x<<" tt "<<y<<" "<<sum<<" "<<v1<<" "<<dep<<"\n";
	add(root,1,1e13,dep,v1);
	ress=max(ress,v1+a[cur]*(dep+1));
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y||vis[e[i].to])continue;
		getadd(e[i].to,x,sum,v1,dep+1);
	}
}
void js(int x,int y)
{
	if(sum==1)
	{
		vis[x]=1;
		ress=max(ress,a[x]);
		return;
	}
	cur=0;find(x,y);int now=cur;
	find(now,0);//size 
	vis[now]=1;cst=0,root=0;//0
//	cout<<now<<" "<<sum<<"\n";
	vector<int>v; 
	for(int i=h[now];i;i=e[i].next)
	{
		if(vis[e[i].to])continue;v.push_back(e[i].to);
		getans(e[i].to,now,a[now],a[now],2);
		getadd(e[i].to,now,0,0,1);
	}
	cst=0,root=0;//0
	for(int i=v.size()-1;i>=0;i--)
	{
		int to=v[i];
		getans(to,now,a[now],a[now],2);
		getadd(to,now,0,0,1);
	}
	for(int i=h[now];i;i=e[i].next)
	{
		if(vis[e[i].to])continue;
		sum=size[e[i].to];
		js(e[i].to,now);
	}
}
int main(){
	n=read();
	for(int i=1;i<n;i++)
	{
		int a,b;
		a=read();
		b=read();
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++)a[i]=read();
	sum=n;
	js(1,0);
	cout<<ress<<"\n";
	return 0;
}