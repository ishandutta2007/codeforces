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
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=55;
int n,m,k,u[MAXN*MAXN],v[MAXN*MAXN],x[MAXN*MAXN],yy[MAXN*MAXN];
bool badin[MAXN],badout[MAXN];
mp y[MAXN*MAXN];
vector<mp> ope[MAXN];
vector<int> ope2[MAXN];
namespace FLOW{
	const int GRAPH_SIZE= 105;
	int s=0,t=GRAPH_SIZE-1;
	struct EDGE{
		int u,v,c,cos;
	};
	vector<EDGE> e;
	vector<int> each[GRAPH_SIZE];
	int maxflow,mincost;
	int flow[GRAPH_SIZE];
	int dis[GRAPH_SIZE],inq[GRAPH_SIZE],las[GRAPH_SIZE];
	bool spfa(){
		memset(inq,0,sizeof(inq));
		memset(dis,63,sizeof(dis));
		flow[s]=INF;
		dis[s]=0;
		queue<int> q;
		q.push(s);
		inq[s]=1;
		while(!q.empty()){
			int now=q.front();
			q.pop();
			inq[now]=0;
			for(auto it:each[now]){
				int to,f,c;
				to=e[it].v;
				f=e[it].c;
				c=e[it].cos;
				if(f<=0) continue;
				if(dis[to]>dis[now]+c){
					dis[to]=dis[now]+c;
					las[to]=it;
					flow[to]=min(flow[now],f);
					if(!inq[to]) q.push(to);
					inq[to]=1;
				}
			}
		}
		return dis[t]!=INF;
	}
	int KM(){
		maxflow=0;
		mincost=0;
		while(spfa()){
			maxflow+=flow[t];
			mincost+=dis[t]*flow[t];
			int now=t;
			while(now!=s){
				e[las[now]].c-=flow[t];
				e[las[now]^1].c+=flow[t];
				now=e[las[now]].u;
			}
		}
		return mincost;
	}
	void make_edge(int U,int V,int C,int COS){
		EDGE tmp;
		tmp.u=U;
		tmp.v=V;
		tmp.c=C;
		tmp.cos=COS;
		e.PB(tmp);
		each[U].PB(e.size()-1);
		swap(tmp.u,tmp.v);
		tmp.c=0;
		tmp.cos=-COS;
		e.PB(tmp);
		each[V].PB(e.size()-1);
	}
	bool check(int T){
		rep(i,GRAPH_SIZE) each[i].clear();
		e.clear();
		make_edge(s,GRAPH_SIZE-2,T,0);
		rb(i,1,n) make_edge((i<<1)-1,(i<<1),1,-1),make_edge((i<<1),t,1,0),make_edge(GRAPH_SIZE-2,(i<<1)-1,1,0);
		rb(i,1,m) if(badin[v[i]]||badout[u[i]]);
		else make_edge(u[i]<<1,(v[i]<<1)-1,1,0);
		return KM()==-n;
	}
}
void gao(int t){
	if(t>k) return ;
	if(FLOW::check(t)){
		rb(i,1,n){
			if(!badin[i]){
				badin[i]=1;
				if(!FLOW::check(t)){
					ope[t].PB(II(y[t].SEC,-i));
					gao(t+1);
					return;
				}
				badin[i]=0;
			}
			if(!badout[i]){
				badout[i]=1;
				if(!FLOW::check(t)){
					ope[t].PB(II(y[t].SEC,i));
					gao(t+1);
					return;
				}
				badout[i]=0;
			}
		}
		assert(0); 
	}
	else gao(t+1);
}
LL get(vector<int> spj){
	int now=1;
	int  cnt=0;
	LL tmp=0;
	for(auto it:spj){
		if(it==0){
			tmp+=max(0ll,x[now]-1ll*cnt*yy[now]);
			cnt=0;
			++now;
			continue;
		}
		++cnt;
	}
	return tmp;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rb(i,1,m) scanf("%d%d",&u[i],&v[i]);
	y[0]=II(INF,INF);
	rb(i,1,k) scanf("%d%d",&x[i],&y[i].FIR),yy[i]=y[i].FIR,y[i].SEC=i,check_min(y[i],y[i-1]);
	gao(1);
	pair<LL,vector<int> > ans;
	ans.FIR=-123;
	rb(i,1,k+1){
		rb(j,1,k) ope2[j].clear();
		vector<int> vvv;
		rb(j,1,i-1) for(auto it:ope[j]) ope2[it.FIR].PB(it.SEC);
		rb(j,i,k) for(auto it:ope[j]) ope2[i].PB(it.SEC);
		rb(j,1,k){
			for(auto it:ope2[j]) vvv.PB(it);
			vvv.PB(0);
		}
		check_max(ans,II(get(vvv),vvv));
	}
	printf("%d\n",int(ans.SEC.size()));
	for(auto it:ans.SEC){
		printf("%d ",it);
	}
	puts("");
	return 0;
}