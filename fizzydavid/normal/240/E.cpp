//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
const int maxn=200111;
int n,m,rt[maxn],ew[maxn];
bool use[maxn];
struct node
{
	int v,lz,tl,tr,to;
	void addlz(int Lz)
	{
		lz+=Lz;
		v+=Lz;
	}
}a[maxn];
int from[maxn],f[maxn];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void pushdown(int p)
{
	if(a[p].lz!=0)
	{
		if(a[p].tl)a[a[p].tl].addlz(a[p].lz);
		if(a[p].tr)a[a[p].tr].addlz(a[p].lz);
		a[p].lz=0;
	}
}
int merge(int p,int q)
{
	if(!p||!q)return p^q;
	pushdown(p);
	if(a[p].v>a[q].v)swap(p,q);
	a[p].tr=merge(a[p].tr,q);
	swap(a[p].tl,a[p].tr);
	return p;
}
void fail()
{
	puts("-1");
	exit(0);
}
int ANS;
bool vis[maxn],inst[maxn];
int st[maxn],stn,out[maxn];
vector<int> ncon[maxn];
void dfs(int x)
{
	assert(gf(x)==x);
	vis[x]=1;
	int &p=rt[x];
	while(true)
	{
		int v=a[p].v,to=gf(a[p].to);
		while(p&&to==x)
		{
			p=merge(a[p].tl,a[p].tr);
			v=a[p].v,to=gf(a[p].to);
		}
		if(!p)fail();
		ncon[a[p].to].PB(p);
		ANS+=v;
		a[p].addlz(-v);
		pushdown(p);
		p=merge(a[p].tl,a[p].tr);
		if(!vis[to])
		{
			st[stn++]=x;
			inst[x]=1;
			dfs(to);
			inst[x]=0;
			if(stn>0&&st[stn-1]==x)stn--;
			break;
		}
		else
		{
			if(inst[to])
			{
				while(st[stn]!=to)
				{
					stn--;
					int q=st[stn];
					f[q]=x;
					rt[x]=merge(rt[x],rt[q]);
				}
			}
			else break;
		}
	}
}
void Minimum_Arborescense()
{
	for(int i=1;i<=n;i++)f[i]=i;
	vis[1]=1;
	for(int i=2;i<=n;i++)if(!vis[i])
	{
		dfs(i);
		assert(stn==0);
	}
}
void pdfs(int x)
{
	vis[x]=1;
	for(int i=0;i<ncon[x].size();i++)
	{
		int e=ncon[x][i];
		int u=from[e];
		if(!vis[u])
		{
			out[u]=e;
			pdfs(u);
		}
	}
}
void print_ans()
{
	memset(vis,0,sizeof(vis));
	pdfs(1);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		swap(x,y);
		ew[i]=w;
		from[i]=x;
		a[i].to=y;
		a[i].v=w;
		rt[x]=merge(rt[x],i);
	}
	Minimum_Arborescense();
	print_ans();
	cout<<ANS<<endl;
	for(int i=2;i<=n;i++)if(ew[out[i]]==1)printf("%d ",out[i]);
	return 0;
}