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
int a[500005];
int b[500005];
int to[500005];
int pre[500005];
int predis[500005];
struct node
{
	int sum,l,r;
	node(){sum=1e9;}
}e[1500005];
int f[500005][19];
int cst;
void insert(int &x,int l,int r,int v,int val)
{
	if(!x)x=++cst;
	e[x].sum=min(e[x].sum,val);
//	cout<<x<<' '<<l<<" "<<r<<" "<<e[x].sum<<endl;
	if(l==r)return;
	int mid=l+r>>1;
	if(v<=mid)insert(e[x].l,l,mid,v,val);
	else insert(e[x].r,mid+1,r,v,val);
}
void merge(int &x,int a,int b,int l,int r)
{
	if(!a||!b)return x=a+b,void();
	x=++cst;
	e[x].sum=min(e[a].sum,e[b].sum);
	int mid=l+r>>1;
	merge(e[x].l,e[a].l,e[b].l,l,mid);
	merge(e[x].r,e[a].r,e[b].r,mid+1,r);
}
int ans;
void ask(int k,int l,int r,int x,int y)
{
	if(!k)return;
	if(r<x||y<l)return;
	if(x<=l&&r<=y)
	{
//		cout<<k<<' '<<l<<" "<<r<<" "<<x<<" "<<y<<" "<<e[k].sum<<endl;
		ans=min(ans,e[k].sum);
		return;
	}
	int mid=l+r>>1;
	ask(e[k].l,l,mid,x,y);
	ask(e[k].r,mid+1,r,x,y);
}
int Log2[1000005];
int tot;
void ask(int x,int y)
{
	ans=2147483647;
	int k=Log2[y-x+1];
	ask(f[x][k],1,n,x,y);
	ask(f[y-(1<<k)+1][k],1,n,x,y);
	if(ans==2147483647)puts("-1");
	else cout<<ans<<"\n";
}
struct nod
{
	int l,r,id,ans;
	bool operator<(const nod&w)const
	{
		return r<w.r;
	}
}w[1000005];
int main(){
//	freopen("a.in","r",stdin);
	Log2[0]=-1;
	for(int i=1;i<=500000;i++)Log2[i]=Log2[i-1]+(i==(i&(-i)));
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read(),b[i]=a[i];
	}
	sort(b+1,b+n+1);
	tot=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+tot+1,a[i])-b;
	memset(to,-1,sizeof(to));
	for(int i=1;i<=n;i++)
	{
		pre[i]=to[a[i]];
		predis[i]=i-pre[i];
		to[a[i]]=i;
	}
//	for(int j=1;j<=18;j++)
//	{
//		for(int i=1;i<=n;i++)
//		{
//			if(i+(1<<j-1)>n)f[i][j]=f[i][j-1];
//			else merge(f[i][j],f[i][j-1],f[i+(1<<j-1)][j-1],1,n);
//		}
//	}
	for(int i=1;i<=m;i++)
	{
		w[i].l=read();
		w[i].r=read();
		w[i].id=i;
	}
	sort(w+1,w+m+1);
	int now=0;
	int root=0;
	for(int i=1;i<=m;i++)
	{
//		cout<<w[i].r<<endl;
		while(now<w[i].r)
		{
			now++;
			if(pre[now]==-1)continue;
//			cout<<pre[now]<<" "<<predis[now]<<" "<<now<<endl;
			insert(root,1,n,pre[now],predis[now]);
		}
		ans=2147483647;
//		cout<<ans<<endl;
		ask(root,1,n,w[i].l,w[i].r);
//		cout<<ans<<endl;
		if(ans==2147483647)ans=-1;
//		cout<<w[now].id<<endl;
		w[w[i].id].ans=ans;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<w[i].ans<<"\n";
	}
//	for(int i=1;i<=n;i++)
//	{
//		if(pre[i]==-1)continue;
//		insert(f[i][0],1,n,pre[i],predis[i]);
//	}
//	while(m--)
//	{
//		int a,b;
//		a=read();
//		b=read();
//		ask(a,b);
//	}
	return 0;
}