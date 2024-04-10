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
const int xx=1e5+5;
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
int a[xx],root[xx],dfx[xx],size[xx],dep[xx];
vector<int>v[xx];
int css;
void dfs(int x,int y)
{
	dep[x]=dep[y]+1;
	v[dep[x]].push_back(x);
	size[x]=1;
	dfx[x]=++css;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		size[x]+=size[e[i].to];
	}
}
struct nod{int mn,l,r;nod(){mn=1e9,l=r=0;}}w[xx*31];
#define e w
int cst;
void insert(int &k,int l,int r,int x,int y)
{
	cst++;e[cst]=e[k];k=cst;
	e[k].mn=min(e[k].mn,y);
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid)insert(e[k].l,l,mid,x,y);
	else insert(e[k].r,mid+1,r,x,y);
}
int ask(int k,int l,int r,int x,int y)
{
//	cout<<k<<" "<<e[k].mn<<"\n";
	if(x<=l&&r<=y)return e[k].mn;
	int mid=l+r>>1;
	int ans=1e9;
//	cout<<x<<" sss "<<y<<"\n";
	if(x<=mid)ans=min(ans,ask(e[k].l,l,mid,x,y));
	if(mid<y)ans=min(ans,ask(e[k].r,mid+1,r,x,y));
	return ans;
}

int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++)
	{
		int a,b;
		a=read();
		b=read();
		add(a,b);
		add(b,a);
	}
	dfs(m,0);
	for(int i=1;i<=n;i++)
	{
		root[i]=root[i-1];
		for(int j=0;j<v[i].size();j++)insert(root[i],1,n,dfx[v[i][j]],a[v[i][j]]);
	}
	m=read();
	int last=0;
	while(m--)
	{
		int x,k;
		x=(read()+last)%n+1;
		k=(read()+last)%n;
		cout<<(last=ask(root[min(n,dep[x]+k)],1,n,dfx[x],dfx[x]+size[x]-1))<<"\n";
	}
	return 0;
}