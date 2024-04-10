/**
 *    author:  gary
 *    created: 30.03.2022 18:26:58
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
const int MAXN=200000+10;
int n,m,fa[MAXN],d[MAXN];
LL dist[MAXN];
vector<pair<mp,int> > edge;
vector<mp> g[MAXN];
int root(int x){return fa[x]=(fa[x]==x? x:root(fa[x]));}
bool dfs(int now){
    for(auto it:g[now]) if(dist[it.first]==1e18){
        dist[it.first]=dist[now]+it.second;
        if(!dfs(it.first)) return 0;
    }
    else if(dist[it.first]!=dist[now]+it.second) return 0;
    return 1;
}
bool check(int x){
    rep(i,MAXN) dist[i]=1e18,fa[i]=i,g[i].clear(),d[i]=0;
    rep(i,x) fa[root(edge[i].first.first)]=root(edge[i].first.second),d[edge[i].first.second]++;
    rep(i,x) g[edge[i].first.first].PB(II(edge[i].first.second,edge[i].second)),g[edge[i].first.second].PB(II(edge[i].first.first,-edge[i].second));
    rb(i,1,n) if(dist[i]==1e18&&d[i]==0){
        dist[i]=0;
        if(!dfs(i)) return 0;
    }
    rb(i,1,n) if(dist[i]==1e18){
        for(auto it:g[i]) if(it.second!=0) return 0;
        dist[i]=0;
    }
    rep(i,x) if(edge[i].first.first==1||edge[i].first.second==n||edge[i].first.second==1||edge[i].first.first==n) if(edge[i].second==0) return 0;
    rep(i,x) if(edge[i].first.second==1||edge[i].first.first==n) return 0;
    if(root(1)==root(n)){
        rep(i,x) if(edge[i].second>dist[n]) return 0;
        if(dist[n]<0) return 0;
        rb(i,1,n) if(dist[i]>dist[n]) return 0;
        rb(i,1,n) if(dist[i]==dist[n]&&root(1)==root(n)&&root(1)!=root(i)) return 0;
    }
    rb(i,1,n) if(i!=1&&root(i)==root(1)&&dist[i]<=0) return 0;
    rb(i,1,n) if(i!=n&&root(i)==root(n)&&dist[i]>=dist[n]) return 0;
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    if(m==0){
        cout<<"UNKNOWN\n";
        return 0;
    }
    rep(i,m){
        int u,v,x,y;
        cin>>u>>v>>x>>y;
        edge.PB(II(II(u,v),x*y));
    }
    if(!check(1)){
        cout<<"BAD 1\n";
        return 0;
    }
    if(check(m)){
        if(root(1)==root(n)){
            cout<<dist[n]<<endl;
        }
        else{
            cout<<"UNKNOWN\n";
        }
        return 0;
    }
    int l=1,r=m;
    while (l<r-1){
        int mid=(l+r)>>1;
        if(check(mid)) l=mid;
        else r=mid;
    }
    cout<<"BAD "<<r<<endl;
    return 0;
}