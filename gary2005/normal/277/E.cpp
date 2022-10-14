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
#define int LL
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/

const int GRAPH_SIZE= 804;
int s=0,t=GRAPH_SIZE-2;
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
	memset(dis,127,sizeof(dis));
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
	return dis[t]<1e18;
}
void KM(){
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
int n;
mp a[404];
int in[404],out[404];
int dist(mp A,mp B){
	double tmp=pow(A.FIR-B.FIR,2)+pow(A.SEC-B.SEC,2);
	return sqrt(tmp)*1e8;
}
signed main(){
	scanf("%lld",&n);
	rb(i,1,n) scanf("%lld%lld",&a[i].FIR,&a[i].SEC);
	rb(i,1,n) in[i]=(i<<1)-1,out[i]=i<<1;
	rb(i,1,n) make_edge(s,out[i],2,0);
//	cout<<s<<endl;
	rb(i,1,n) make_edge(in[i],t,1,0);
	rb(i,1,n) rb(j,1,n) if(i!=j&&a[i].SEC>a[j].SEC) make_edge(out[i],in[j],1,dist(a[i],a[j]));
	KM();
	if(maxflow!=n-1){
		cout<<-1<<endl;
	}
	else{
		printf("%.10f\n",1.0*mincost/1e8);
	}
	return 0;
}