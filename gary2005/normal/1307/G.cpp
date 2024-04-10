/**
 *    author:  gary
 *    created: 15.02.2022 13:01:03
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
const int MAXN=51;
struct mincost_flow{
    struct edge{
        int v,w,c;
    };
    vector<edge> e;
    vector<int> g[MAXN];
    bool inq[MAXN];
    int dist[MAXN];
    int pre[MAXN],pree[MAXN];
    void addedge(int u,int v,int w,int c){
        e.PB(edge{v,w,c});
        g[u].PB(e.size()-1);
        e.PB(edge{u,-w,0});
        g[v].PB(e.size()-1);
    }
    bool spfa(int s,int t){
        queue<int> q;
        memset(dist,63,sizeof(dist));
        memset(inq,0,sizeof(inq));
        dist[s]=0;
        inq[s]=1;
        q.push(s);
        while(!q.empty()){
            int now=q.front();q.pop();
            inq[now]=0;
            for(auto it:g[now]){
                if(e[it].c&&dist[e[it].v]>dist[now]+e[it].w){
                    dist[e[it].v]=dist[now]+e[it].w;
                    pre[e[it].v]=now;
                    pree[e[it].v]=it;
                    if(!inq[e[it].v]){
                        inq[e[it].v]=1;
                        q.push(e[it].v);
                    }
                }
            }
        }
        return dist[t]!=INF;
    }
    vector<int> go(int s,int t){
        vector<int> rest;
        while(spfa(s,t)){
            rest.PB(dist[t]);
            int now=t;
            while(now!=s){
                e[pree[now]].c--;
                e[pree[now]^1].c++;
                now=pre[now];
            }
        }
        return rest;
    }
}flow;
int n,m;
int main(){
    cin>>n>>m;
    rb(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        flow.addedge(u,v,w,1);
    }
    auto ve=flow.go(1,n);
    int Q;
    cin>>Q;
    while(Q--){
        int xi;
        cin>>xi;
        long double answer=1e18;
        long double sum=0;
        rep(i,ve.size()){
            sum+=ve[i];
            check_min(answer,(sum+xi)/(i+1));
        }
        printf("%.10Lf\n",answer);
    }
    return 0;
}
/*

3 3
1 2 2
2 3 2
1 3 3
5
0
1
2
3
4



*/