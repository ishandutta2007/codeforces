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

const int GRAPH_SIZE= 2000*2;
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
void KM(){
	while(spfa()){
		if(dis[t]>0) break;
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
const int MAXN=2200;
int d,n;
bitset<11> a[MAXN];
vector<int> g[MAXN];
int in[MAXN],out[MAXN]; 
vector<int> rest;
vector<int> T;
void print(int now){
	if(now==t) return ;
	auto it=g[now].back();
	g[now].POB();
	print(it);
	if(now<=n&&now>=1&&it>n&&it<=2*n){
		T.PB(now);
	}
	return;
}
int main(){
//	freopen("test.in","r",stdin);
	scanf("%d%d",&d,&n);
	rb(i,1,n){
		in[i]=i;
		out[i]=i+n;
		make_edge(in[i],out[i],1,-1e6);
	}
	rb(i,1,n){
		rep(j,d){
			char c;
			cin>>c;
			a[i][j]=c^48;
		}
	}
	rb(i,1,n) rb(j,1,n) if(i!=j&&(a[i]&a[j]).count()==a[j].count()){
		make_edge(out[i],in[j],1,0);
	}
	rb(i,1,n){
		make_edge(s,in[i],1,a[i].count()+1);
	}
	rb(i,1,n){
		make_edge(out[i],t,1,0);
	}
	KM();
	rep(i,e.size()){
		if(i&1);
		else{
			if(e[i^1].c){
				g[e[i].u].PB(e[i].v);
			}
		}
	}
	for(auto it:g[s]){
		if(rest.size()){
			rest.PB(-1);
		}
		T.clear();
		print(it);
		bitset<11> pre;
		for(auto it:T){
			rep(j,d){
				if(a[it][j]&&!pre[j]){
					rest.PB(j);
				}
			}
			pre=a[it];
		}
	}
	cout<<rest.size()<<endl;
	for(auto it:rest){
		if(it==-1){
			cout<<"R ";
		}
		else{
			cout<<it<<' '; 
		}
	}
	return 0;
}