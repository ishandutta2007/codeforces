#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read() {
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
int a[1000005];
int change(int x,int y)
{
	return (x-1)*n+y;
}
pair<int,int>change(int x)
{
	return make_pair((x-1)/n+1,(x-1)%n+1);
}
int vis[100005];
int fa[1000005];
int find(int x)
{
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)return;
	fa[x]=y;
}
ll nowans=1e18,sizee;
void dfs(int x,int size)
{
	if(size>=n)return;
	if(x==n*n+1)
	{
		if(size!=n-1)return;
		for(int i=1;i<=n;i++)fa[i]=i;
		ll ans=0;
		for(int i=1;i<=n*n;i++)
		{
			if(vis[i])merge(change(i).first,change(i).second),ans+=a[change(i).first]^a[change(i).second];
		}
		int res=0;
		for(int i=1;i<=n;i++)if(find(i)==i)res++;
		if(res==1)
		{
			if(ans<nowans)
			{
				sizee=0;
				nowans=ans;
			}
			if(ans==nowans)sizee++;
		}
		return;
	}
	if(change(x).first>=change(x).second)
	{
		vis[x]=0;
		dfs(x+1,size);
		return;
	}
	vis[x]=1;
	dfs(x+1,size+1);
	vis[x]=0;
	dfs(x+1,size);
}
struct trie
{
	int to[2];
	int maxx,minn;
	int ts;
}e[6400005];
int cst;
void insert(int num,int bel,int id)
{
	int last=0;
	for(int i=30;i>=0;i--)
	{
		int w=((num>>i)&1);
		if(!e[last].to[w])e[last].to[w]=++cst;
		e[last].maxx=max(e[last].maxx,bel);
		if(e[last].minn==0)e[last].minn=bel;
		e[last].minn=min(e[last].minn,bel);
		last=e[last].to[w];
	}
	e[last].maxx=max(e[last].maxx,bel);
	if(e[last].minn==0)e[last].minn=bel;
	e[last].minn=min(e[last].minn,bel);
	e[last].ts=id;
}
int tot;
ll ans=0;
int search(int num,int bel)
{
	int last=0;
	for(int i=30;i>=0;i--)
	{
		int w=((num>>i)&1);
		if(!e[last].to[!w])
		{
			last=e[last].to[w];continue;
		}
		if(!e[last].to[w])
		{
			last=e[last].to[!w];continue;
		}
		if(e[e[last].to[w]].maxx!=bel||e[e[last].to[w]].minn!=bel)
		{
			last=e[last].to[w];continue;
		}
		last=e[last].to[!w];continue;
	}
	return e[last].ts;
}
ll v[1000005];
int p[1000005];
void boruvka()
{
	cst=0;
	if(tot==n-1)return;
	memset(e,0,sizeof(e));
	memset(v,0x3f,sizeof(v));
	memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++)insert(a[i],find(i),i);
	for(int i=1;i<=n;i++)
	{
		int w=search(a[i],find(i));
		if((a[i]^a[w])<v[find(i)])
		{
			v[find(i)]=a[i]^a[w];
			p[find(i)]=w;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(find(i)==i)
		{
			if(find(i)!=find(p[i]))
			{
				merge(i,p[i]);
//				cout<<v[i]<<endl;
				ans+=v[i];
				tot++;
			}
		}
	}
//	cout<<tot<<endl;
	boruvka();
}
signed main() {
//	freopen("a.in","r",stdin);
	n=read();
//	cout<<n<<endl;
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1])merge(find(i),find(i-1)),tot++;
	}
//	cout<<tot<<endl;
	boruvka();
	cout<<ans<<endl;
	return 0;
}