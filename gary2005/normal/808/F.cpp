/**
 *    author:  gary
 *    created: 28.10.2021 18:07:45
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
const int GRAPH_SIZE= 110;
int pin[GRAPH_SIZE],dep[GRAPH_SIZE],s=0,t=GRAPH_SIZE-1;
struct EDGE{
	int u,v,c;
};
vector<EDGE> e;
vector<int> each[GRAPH_SIZE];
bool bfs(){
	queue<int> Q;
	Q.push(s);
	while(!Q.empty()){
		int now=Q.front();
		Q.pop();
		for(auto it:each[now]){
			int next=e[it].v;
			if(e[it].c)
			if(dep[next]>dep[now]+1){
				dep[next]=dep[now]+1;
				Q.push(next);
			}
		}
	}
	return dep[t]!=INF;
}
int dfs(int now,int flow){
	if(now==t){
		return flow;
	}
	for(int & i= pin[now];i<each[now].size();i++){
		int it=each[now][i];
		if(e[it].c&&dep[e[it].v]==dep[now]+1){
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
	rep(i,GRAPH_SIZE)
	{
		
		dep[i]=INF;
	}
	dep[s]=0;
	while(bfs()){
		rep(i,GRAPH_SIZE){
			pin[i]=0;
		}
		int tmp;
		while(tmp=dfs(s,INF)){
			max_flow+=tmp;
		}
		rep(i,GRAPH_SIZE){
			dep[i]=INF;
		}
		dep[s]=0;
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
void init(){
	e.clear();
	rep(i,GRAPH_SIZE){
		each[i].clear();
	}
}
const int MAXN=105;
tuple<int,int,int> cards[MAXN];
bool cmp(tuple<int,int,int> A,tuple<int,int,int> B){
    return get<2>(A)<get<2>(B);
}
int prime[100000+100000+1];
int main(){
    fill(prime,prime+200000+1,1);
    rb(i,2,200000){
        if(prime[i]){
            for(int j=i+i;j<=200000;j+=i){
                prime[j]=0;
            }
        }
    }
    int n,k;
    scanf("%d%d",&n,&k);
    rb(i,1,n){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        cards[i]=make_tuple(a,b,c);
    }
    sort(cards+1,cards+1+n,cmp);
    rb(i,1,n){
        init();
        vector<mp> V;
        int mx=-INF;
        rb(j,1,i){
            if(get<1>(cards[j])==1) check_max(mx,get<0>(cards[j]));
            else V.PB(II(get<1>(cards[j]),get<0>(cards[j])));
        }
        if(mx!=-INF) V.PB(II(1,mx));
        int tot=0;
        for(auto it:V){
            tot+=it.SEC;
        }
        rep(i,V.size()) rep(j,i) {
            if(prime[V[i].FIR+V[j].FIR]){
                if(V[i].FIR&1) make_edge(i+1,j+1,INF);
                else make_edge(j+1,i+1,INF);
            }
        }
        rep(i,V.size()){
            if(V[i].FIR&1) make_edge(s,i+1,V[i].SEC);
            else make_edge(i+1,t,V[i].SEC);
        }
        if(tot-Dinic()>=k) {
            printf("%d\n",get<2>(cards[i]));
            return 0;
        }
    }
    printf("%d\n",-1);
    return 0;
}