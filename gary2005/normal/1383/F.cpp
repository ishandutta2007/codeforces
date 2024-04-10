/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
inline int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int GRAPH_SIZE= 1e4+1;
int s=0,t=GRAPH_SIZE-1;
struct EDGE{
	int u,v,c;
};
vector<EDGE> e;
vector<int> each[GRAPH_SIZE];
int pin[GRAPH_SIZE];
int vis[GRAPH_SIZE];
int cnt=0;
int dfs(int now,int flow){
	if(now==t){
		return flow;
	}
	vis[now]=cnt;
	for(int &i= pin[now];i<each[now].size();i++){
		int it=each[now][i];
		if(e[it].c&&cnt!=vis[e[it].v]){
			int tmp;
			if(tmp=dfs(e[it].v,min(flow,e[it].c))){
				e[it].c-=tmp;
				e[it^1].c+=tmp;
				return tmp;
			}
		}
	}
	return 0;
}
int Dinic(){
	int max_flow=0;
	for (bool ok = true; ok; )
	{
		int it = 0;
		fill(pin+1,pin+GRAPH_SIZE,0);
		for (int f; ; ++it)
		{
			++cnt;
			f = dfs(s, 25);
			if (f == 0)
			{
				if (it == 0) ok = false;
				break;
			}
			max_flow += f;
		}
	}
	return max_flow;
}
void make_edge(int U,int V,int C){
	EDGE tmp;
	tmp.u=U;
	tmp.v=V;
	tmp.c=C;
	e.PB(tmp);
	each[U].PB(e.size()-1);
	swap(tmp.u,tmp.v);
	tmp.c=0;
	e.PB(tmp);
	each[V].PB(e.size()-1);
}
const int MAXN=1e4+233;
int n,m,k,q;
int u[MAXN],v[MAXN],w[MAXN],mf[1<<10],sum[1<<10];
void graph_init(){
	e.clear();
	rep(i,GRAPH_SIZE) each[i].clear();
}
int lg[1<<10];
void calc(int mask,int dep,int pre){
	if(dep==k) {
		mf[mask]=pre;
		return ;	
	}
	vector<EDGE> old=e;
	vector<int> olde[GRAPH_SIZE];
	rep(i,GRAPH_SIZE) olde[i]=each[i];
	calc(mask,dep+1,pre);
	rep(i,GRAPH_SIZE) each[i]=olde[i];
	e=old;
	make_edge(u[dep+1],v[dep+1],25);
	calc(mask|(1<<dep),dep+1,pre+Dinic());
} 
void relabel(){
	vector<int> g[MAXN];
	int nu[MAXN],nv[MAXN],nw[MAXN];
	bool used[MAXN]={0};
	int cnt=k;
	rb(i,1,k){
		used[i]=1;
		nu[i]=u[i],nv[i]=v[i],nw[i]=w[i];
	}
	rb(i,1,m) g[u[i]].PB(i); 
	int id[MAXN];
	fill(id+1,id+1+n,-1);
	id[1]=1,id[n]=n;
	int sz=1;
	function<void(int)> dfs=[&] (int now){
		for(auto it:g[now]){
			if(!used[it]){
				nu[++cnt]=u[it];
				nv[cnt]=v[it];
				nw[cnt]=w[it];
				used[it]=1;
			}
			if(id[v[it]]==-1){
				id[v[it]]=++sz;
				dfs(v[it]);
			}
		}
	};
	dfs(1);
	rb(i,1,n) if(id[i]==-1) id[i]=++sz;
	rb(i,1,m){
		if(!used[i]){
			nu[++cnt]=u[i];
			nv[cnt]=v[i];
			nw[cnt]=w[i];
			used[i]=1;
		}
	}
	rb(i,1,m) u[i]=id[nu[i]],v[i]=id[nv[i]],w[i]=nw[i];
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&q);
	rb(i,1,m){
		u[i]=read();
		v[i]=read();
		w[i]=read();
	}
	relabel();
	s=1,t=n;
	rb(i,k+1,m){
		make_edge(u[i],v[i],w[i]);
	}
	memset(mf,63,sizeof(mf));
	calc(0,0,Dinic());
	rb(i,1,k) lg[1<<(i-1)]=i;
	rb(i,1,q){
		rb(j,1,k) w[j]=read();
		int rest=INF;
		sum[0]=0;
		rep(mask,1<<k){
			sum[mask]=0;
			if(mask) sum[mask]+=sum[mask^(mask&(-mask))]+w[lg[mask&(-mask)]];
			check_min(rest,sum[mask]+mf[((1<<k)-1)^mask]);
		}
		printf("%d\n",rest);
	}
	return 0;
}