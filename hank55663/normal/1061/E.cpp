/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<assert.h>
#include<map>
#include<set>
#include<utility>
#include<iostream>
#include<cmath>
#include<sstream>
#include<queue>
#include<bitset>*/
#include<bits/stdc++.h>
#define LL long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
#define search Search
#define index Index
#define transform Transform
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
struct CostFlow {
    static const int MXN = 2005;
    static const long long INF = 102938475610293847LL;
    struct Edge {
        int v, r;
        long long f, c;
        Edge(int a,int b,int _c,int d):v(a),r(b),f(_c),c(d){
		}
    };
    int n, s, t, prv[MXN], prvL[MXN], inq[MXN];
    long long dis[MXN], fl, cost;
    vector<Edge> E[MXN];
    void init(int _n, int _s, int _t) {
        n = _n; s = _s; t = _t;
        for (int i=0; i<n; i++) E[i].clear();
        fl = cost = 0;
    }
    void add_edge(int u, int v, long long f, long long c)
    {
     //   printf("%d %d %lld %lld\n",u,v,f,c);
        E[u].pb(Edge(v, E[v].size() , f, c));
        E[v].pb(Edge(u, E[u].size()-1, 0, -c));
    }
    pll flow() {
        while (true) {
            for (int i=0; i<n; i++) {
                dis[i] = INF;
                inq[i] = 0;
            }
            dis[s] = 0;
            queue<int> que;
            que.push(s);
            while (!que.empty()) {
                int u = que.front(); que.pop();
                inq[u] = 0;
                for (int i=0; i<E[u].size(); i++) {
                    int v = E[u][i].v;
                    long long w = E[u][i].c;
                    if (E[u][i].f > 0 && dis[v] > dis[u] + w) {
                        prv[v] = u; prvL[v] = i;
                        dis[v] = dis[u] + w;
                        if (!inq[v]) {
                            inq[v] = 1;
                            que.push(v);
                        }
                    }
                }
            }
            if (dis[t] == INF) break;
            long long tf = INF;
            for (int v=t, u, l; v!=s; v=u) {
                u=prv[v]; l=prvL[v];
                tf = min(tf, E[u][l].f);
            }
            for (int v=t, u, l; v!=s; v=u) {
                u=prv[v]; l=prvL[v];
                E[u][l].f -= tf;
                E[v][E[u][l].r].f += tf;
            }
            cost += tf * dis[t];
            fl += tf;
        }
        return {fl, cost};
    }
}flow;
vector<int> v1[505];
vector<int> v2[505];
int k1[505];
int label1[505];
int k2[505];
int label2[505];
int dfs(int a,int f,vector<int> *v,int *k,int *label,int labelnum,int add){
    int sum=0;
    if(label[a])
    sum=k[a],labelnum=label[a];
    if(add==0)
    flow.add_edge(labelnum+1000+add,a+add,1,0);
    else
    flow.add_edge(a+add,labelnum+1500,1,0);

    for(auto it:v[a]){
        if(it!=f){
            if(label[a]){
                int x=dfs(it,a,v,k,label,labelnum,add);
                k[a]-=x;
            }
            else{
                sum+=dfs(it,a,v,k,label,labelnum,add);
            }
        }
    }
    if(k[a]<0){
        printf("-1");
        exit(0);
    }
    if(label[a]){
        if(add==0)
        flow.add_edge(0,1000+label[a],k[a],0);
        else
        flow.add_edge(1500+label[a],2001,k[a],0);
    }
    return sum;
}
int main(){
    int n,x,y;
    scanf("%d %d %d",&n,&x,&y);
    int cost[505];
    flow.init(2002,0,2001);
    for(int i=1;i<=n;i++){
        scanf("%d",&cost[i]);
        flow.add_edge(i,i+500,1,-cost[i]);
    }
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v1[x].pb(y);
        v1[y].pb(x);
    }
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v2[x].pb(y);
        v2[y].pb(x);
    }
    int q1;
    scanf("%d",&q1);
    for(int i=1;i<=q1;i++){
        int k,x;
        scanf("%d %d",&k,&x);
        k1[k]=x;
        label1[k]=i;
    }
    int q2;
    scanf("%d",&q2);
    for(int i=1;i<=q2;i++){
        int k,x;
        scanf("%d %d",&k,&x);
        k2[k]=x;
        label2[k]=i;
    }
    if(k1[x]!=k2[y]){
        printf("-1\n");
        return 0;
    }
    int need=k1[x];
    dfs(x,0,v1,k1,label1,0,0);
    dfs(y,0,v2,k2,label2,0,500);
    pll p =flow.flow();
    if(p.x!=need){
        printf("-1\n");
        return 0;
    }
    else{
        printf("%lld\n",-p.y);
    }
}