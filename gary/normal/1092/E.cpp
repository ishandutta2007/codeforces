/**
 *    author:  gary
 *    created: 06.10.2021 14:40:08
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
const int MAXN=1e3+1;
int n,m;
vector<int> g[MAXN];
int fa[MAXN];
mp p[MAXN];
int root(int x){
    return fa[x]=(fa[x]==x? x:root(fa[x]));
}
int dfs(int now,int pre=0,int depth=0){
    int rest=depth;
    for(auto it:g[now]) if(it!=pre) check_max(rest,dfs(it,now,depth+1));
    return rest;
}
mp dfs2(int now,int pre=0,int dis=0){
    mp rest=II(dis,now);
    for(auto it:g[now]) if(it!=pre) check_max(rest,dfs2(it,now,dis+1));
    return rest;
}
int main(){
    scanf("%d%d",&n,&m);
    rb(i,1,n) fa[i]=i;
    rb(i,1,m){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].PB(v);
        g[v].PB(u);
        fa[root(u)]=root(v);
    }
    rb(i,1,n) p[i]=II(INF,INF);
    rb(i,1,n) check_min(p[root(i)],II(dfs(i),i));
    vector<mp> Tmp;
    rb(i,1,n) if(root(i)==i) Tmp.PB(p[i]);
    sort(ALL(Tmp));
    vector<mp> Ans;
    rep(i,Tmp.size()-1){
        Ans.PB(II(Tmp[i].SEC,Tmp.back().SEC));
        g[Tmp[i].SEC].PB(Tmp.back().SEC);
        g[Tmp.back().SEC].PB(Tmp[i].SEC);
    }
    mp A=dfs2(1);
    cout<<dfs2(A.SEC).FIR<<endl;
    for(auto it:Ans){
        printf("%d %d\n",it.FIR,it.SEC);
    }
    return 0;
}