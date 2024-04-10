/**
 *    author:  gary
 *    created: 05.11.2021 19:53:16
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
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
int n,q;
int l[55],r[55];
int main(){
    scanf("%d%d",&n,&q);
    rb(i,1,n) l[i]=1,r[i]=n;
    rb(i,1,q){
        int ty,L,R,v;
        scanf("%d%d%d%d",&ty,&L,&R,&v);
        if(ty==1){
            rb(x,L,R) check_max(l[x],v);
        }
        else{
            rb(x,L,R) check_min(r[x],v);
        }
    }
	rb(i,1,n){
		rb(j,1,n){
			make_edge(s,i,1,j*j-(j-1)*(j-1));
		}
	}
	rb(i,1,n){
		if(l[i]>r[i]){
			cout<<"-1"<<endl;
			return 0;
		}
		rb(j,l[i],r[i]){
			make_edge(j,i+n,1,0);
		}
	}
	rb(i,1,n) make_edge(i+n,t,1,0);
	KM();
	cout<<mincost<<endl;
    return 0;
}