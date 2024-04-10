//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1011;
const int maxm=2011;
ull seed[100111];
int ANSTYPE;
void failed()
{
	ANSTYPE=2;
}
struct Tree
{
	int n;
	vector<int> con[maxn];
	int head[maxn],nxt[maxm],to[maxm],tot;
	int rt[maxn],P;
	ull hs_e[maxm],hs_v[maxm],hs_esum[maxn];
	vector<int> rts;
	ull hs_rtsum;
	Tree(){tot=1;}
	void add_edge(int x,int y)
	{
		nxt[++tot]=head[x];
		head[x]=tot;
		to[tot]=y;
		swap(x,y);
		nxt[++tot]=head[x];
		head[x]=tot;
		to[tot]=y;
	}
	bool ban[maxn];
	int arr[maxn],an,sz[maxn],fa[maxn];
	void dfs_sz(int x,int pre)
	{
		arr[an++]=x;
		sz[x]=1;
		for(int i=head[x];i;i=nxt[i])
		{
			int u=to[i];
			if(ban[u]||u==pre)continue;
			fa[u]=x;
			dfs_sz(u,x);
			sz[x]+=sz[u];
		}
	}
	pair<int,int> findroot(int x)
	{
		an=0;
		dfs_sz(x,-1);
		int ret=x;
		for(int i=0;i<an;i++)if(sz[arr[i]]*2>=sz[x]&&sz[arr[i]]<sz[ret])ret=arr[i];
		if(sz[ret]*2==sz[x])return MP(ret,fa[ret]);
		else return MP(ret,-1);
	}
	ull tmp_hs[maxn];
	ull dfs_hash(int x,int pre)
	{
		ull ret=1;
		int cnt=0;
		for(int i=head[x];i;i=nxt[i])
		{
			int u=to[i];
			if(ban[u]||u==pre)continue;
			ret*=dfs_hash(u,x);
			cnt++;
		}
		ret+=seed[cnt];
		tmp_hs[x]=ret;
		return ret;
	}
	ull calc_hash(int x)
	{
		pair<int,int> pp=findroot(x);
		ull ret;
		if(pp.SS==-1)ret=dfs_hash(pp.FF,-1);
		else ret=min(dfs_hash(pp.FF,-1),dfs_hash(pp.SS,-1));
		return ret;
	}
	ull calc_edge_hash(int e)
	{
		ban[to[e^1]]=1;
		ull ret=calc_hash(to[e]);
		ban[to[e^1]]=0;
		return ret;
	}
	void dfs_rt(int x,int pre)
	{
		for(int i=head[x];i;i=nxt[i])
		{
			int u=to[i];
			if(u==pre)continue;
			rt[u]=rt[x];
			dfs_rt(u,x);
		}
	}
	void prework()
	{
		memset(ban,0,sizeof(ban));
		for(int i=2;i<=tot;i++)hs_e[i]=calc_edge_hash(i);
		for(int i=1;i<=n;i++)
		{
			hs_esum[i]=0;
			for(int j=head[i];j;j=nxt[j])hs_esum[i]+=hs_e[j];
		}
		memset(rt,0,sizeof(rt));
		rts.clear();
		hs_rtsum=0;
		for(int i=1;i<=n;i++)
		{
			if(rt[i]==0)
			{
				rts.PB(i);
				rt[i]=i;
				dfs_rt(i,-1);
				hs_v[i]=calc_hash(i);
				hs_rtsum+=hs_v[i];
			}
		}
		P=-1;
		for(int i=1;i<=n;i++)if(is_single(i))P=i;
		if(P==-1)failed();
		hs_rtsum-=hs_v[P];
	}
	void input(int N,int m)
	{
		tot=1;
		memset(head,0,sizeof(head));
		memset(rt,0,sizeof(rt));
		n=N;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add_edge(x,y);
		}
		prework();
	}
	int find_hash(int x,ull hs,int pre)
	{
		if(dfs_hash(x,-1)==hs)return x;
		for(int i=head[x];i;i=nxt[i])
		{
			int u=to[i];
			if(ban[u]||u==pre)continue;
			int tmp=find_hash(u,hs,x);
			if(tmp!=-1)return tmp;
		}
		return -1;
	}
	bool is_single(int x){return head[x]==0;}
	bool is_leaf(int x){return nxt[head[x]]==0;}
}T1,T2;
int n;
void find_ans(int x,int y,int ex,int ey)
{
	vector<pair<int,int> > E;
	T1.ban[x]=1;
	T2.ban[y]=1;
	vector<pair<ull,int> > v1,v2;
	int P=T1.P;
	for(int i=0;i<T1.rts.size();i++)
	{
		int rt=T1.rts[i];
		if(rt==P)continue;
		if(rt!=T1.rt[x])v1.PB(MP(T1.hs_v[rt],rt));
		else
		{
			if(ex!=-1)
			{
				v1.PB(MP(T1.hs_e[ex],T1.to[ex]));
			}
		}
	}
	assert(P!=-1);
	if(ex==-1)E.PB(MP(P,x));
	sort(v1.begin(),v1.end());
	for(int i=T2.head[y];i;i=T2.nxt[i])v2.PB(MP(T2.hs_e[i],T2.to[i]));
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	assert(v1.size()==v2.size());
	for(int i=0;i<v1.size();i++)
	{
		int g=v1[i].SS;
		ull vhs=T2.dfs_hash(v2[i].SS,-1);
		int tmp=T1.find_hash(g,vhs,-1);
		assert(tmp!=-1);
		E.PB(MP(P,tmp));
	}
	puts("YES");
	assert(T1.tot/2+E.size()==n-1);
	for(int i=2;i<=T1.tot;i+=2)printf("%d %d\n",T1.to[i],T1.to[i^1]);
	for(int i=0;i<E.size();i++)printf("%d %d\n",E[i].FF,E[i].SS);
	ANSTYPE=1;
	
}
void SOLVE()
{
	int k,m1,m2;
	ANSTYPE=0;
	scanf("%d%d",&n,&k);
	scanf("%d",&m1);
	T1.input(n,m1);
	scanf("%d",&m2);
	T2.input(n,m2);
	for(int i=2;i<=T1.tot&&!ANSTYPE;i++)
	{
		int x=T1.to[i^1];
		if(x==T1.P)continue;
		for(int j=2;j<=T2.tot&&!ANSTYPE;j++)
		{
			int y=T2.to[j^1];
			if(y==T2.P)continue;
			if(T1.hs_e[i]!=T2.hs_e[j])continue;
			if(T1.hs_esum[x]-T1.hs_e[i]!=T2.hs_rtsum-T2.hs_v[T2.rt[y]])continue;
			if(T1.hs_rtsum-T1.hs_v[T1.rt[x]]!=T2.hs_esum[y]-T2.hs_e[j])continue;
			find_ans(x,y,i,j);
		}
	}
	if(ANSTYPE==2)
	{
		puts("NO");
		return;
	}
	for(int i=1;i<=n&&!ANSTYPE;i++)
	{
		int x=i;
		if(x==T1.P)continue;
		for(int j=1;j<=n&&!ANSTYPE;j++)
		{
			int y=j;
			if(y==T2.P)continue;
			if(T1.hs_esum[x]!=T2.hs_rtsum-T2.hs_v[T2.rt[y]])continue;
			if(T1.hs_rtsum-T1.hs_v[T1.rt[x]]!=T2.hs_esum[y])continue;
			find_ans(x,y,-1,-1);
		}
	}
	if(ANSTYPE==1)return;
	puts("NO");
}
int main()
{
	srand(time(NULL));
	int Tn;
	scanf("%d",&Tn);
	for(int i=0;i<=100000;i++)
	{
		seed[i]=seed[i]*((ll)RAND_MAX+1)+rand();
		seed[i]=seed[i]*((ll)RAND_MAX+1)+rand();
		seed[i]=seed[i]*((ll)RAND_MAX+1)+rand();
		seed[i]=seed[i]*((ll)RAND_MAX+1)+rand();
	}
	while(Tn--)SOLVE();
	return 0;
}