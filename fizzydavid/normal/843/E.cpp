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
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
namespace Flow
{
	const int maxn=111,maxe=1111*2;
	int head[maxn],to[maxe],nxt[maxe],cap[maxe],tot=1;
	int dg[maxn];
	void init()
	{
		memset(head,0,sizeof(head));tot=1;
		memset(dg,0,sizeof(dg));
	}
	void adde(int x,int y,int c,int lb=0)
	{
//		cerr<<"adde:"<<x<<","<<y<<" "<<c<<" "<<lb<<endl;
		c-=lb;
		nxt[++tot]=head[x];
		head[x]=tot;
		to[tot]=y;
		cap[tot]=c;
		nxt[++tot]=head[y];
		head[y]=tot;
		to[tot]=x;
		cap[tot]=0;
		dg[x]+=lb;dg[y]-=lb;
	}
	void adde_2(int x,int y,int c,int c2)
	{
//		cerr<<"adde:"<<x<<","<<y<<" "<<c<<" "<<lb<<endl;
		nxt[++tot]=head[x];
		head[x]=tot;
		to[tot]=y;
		cap[tot]=c;
		nxt[++tot]=head[y];
		head[y]=tot;
		to[tot]=x;
		cap[tot]=c2;
	}
	
	int lv[maxn],q[maxn],qn;
	void bfs(int S,int N)
	{
		for(int i=0;i<=N;i++)lv[i]=-1;
		qn=0;
		q[qn++]=S;lv[S]=0;
		for(int i=0;i<qn;i++)
		{
			int u=q[i];
			for(int j=head[u];j;j=nxt[j])
			{
				if(cap[j]&&lv[to[j]]==-1)
				{
					lv[to[j]]=lv[u]+1;
					q[qn++]=to[j];
				}
			}
		}
	}
	int it[maxn];
	int dfs(int x,int T,int f)
	{
		if(x==T)return f;
		int of=f;
		for(int &i=it[x];i&&f;i=nxt[i])
		{
			int u=to[i];
			if(cap[i]&&lv[u]==lv[x]+1)
			{
				int d=dfs(u,T,min(f,cap[i]));
				if(d)
				{
					cap[i]-=d;
					cap[i^1]+=d;
					f-=d;
				}
			}
		}
		return of-f;
	}
	int max_flow(int S,int T,int N=-1)
	{
		int ans=0;
		while(true)
		{
			bfs(S,N);
			if(lv[T]==-1)return ans;
			for(int i=0;i<=N;i++)it[i]=head[i];
			int f;
			while(f=dfs(S,T,2147483647))ans+=f;
		}
	}
	bool find_bound_flow(int s,int t,int N=-1)
	{
		if(N==-1)N=maxn-5;
		int S=N+1,T=N+2,pf=0;
		for(int i=0;i<=N;i++)
		{
			if(dg[i]>0)adde(i,T,dg[i]),pf+=dg[i];
			if(dg[i]<0)adde(S,i,-dg[i]);
			dg[i]=0;
		}N+=2;
		adde(t,s,2147483647);
		int flow=max_flow(S,T,N);
		return flow==pf;
	}
};
int n,m,S,T;
int ex[2333],ey[2333],ec[2333];
bool is_cut[2333];
int main()
{
	cin>>n>>m>>S>>T;
	for(int i=1;i<=m;i++)
	{
		int x,y,c;
		cin>>x>>y>>c;
		ex[i]=x;ey[i]=y;ec[i]=c;
		if(c==0)c=mod,Flow::adde(x,y,c);
		else Flow::adde_2(x,y,c,233333333);
	}
	ll flow=Flow::max_flow(S,T,n);
//	cerr<<"min_cut="<<flow<<endl;
	if(flow<0||flow>m)
	{
		cout<<"Unexpected flow = "<<flow<<endl;
		assert(false);
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		if(ec[i]==0)continue;
		is_cut[i]=(Flow::lv[ex[i]]==-1)^(Flow::lv[ey[i]]==-1);
		ans+=is_cut[i];
	}
	if(ans!=flow)
	{
		cout<<"Unexpected cut="<<ans<<" flow="<<flow<<endl;
		assert(false);
	}
	Flow::init();
	for(int i=1;i<=m;i++)Flow::adde(ex[i],ey[i],ec[i]*233333333,ec[i]>0);
	if(!Flow::find_bound_flow(S,T,n))
	{
		cout<<"Cannot find suitable solution"<<endl;
		for(int i=1;i<=m;i++)cerr<<ec[i]<<endl;
		assert(false);
	}
	cout<<ans<<endl;
	for(int i=1;i<=m;i++)
	{
		int f=Flow::cap[i<<1|1]+(ec[i]>0);
		if(ec[i]==0)cout<<0<<" "<<1<<endl;
		else if(is_cut[i])cout<<f<<" "<<f<<endl;
		else cout<<f<<" "<<f+1<<endl;
	}
	return 0;
}