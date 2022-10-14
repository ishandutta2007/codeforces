/**
 *    author:  gary
 *    created: 30.03.2022 22:23:41
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
const int MAXN=1e5+10;
int n;
vector<mp> g[MAXN];
vector<mp> event[MAXN];
map<int,int> pos[MAXN],neg[MAXN];
priority_queue<pair<int,mp> ,vector<pair<int,mp> > ,greater<pair<int,mp > > > diff[MAXN];
int tag[MAXN];
void add_pos(int v,int x,int val,bool ty=1,bool ty2=1){
    x+=tag[v];
    auto ite=neg[v].upper_bound(x-2*tag[v]);
    if(ite!=neg[v].begin()&&ty2)
    diff[v].push(II(x-prev(ite)->first,II(prev(ite)->first,x)));
    if(ty)
    pos[v][x]+=val;
}
void add_neg(int v,int x,int val,bool ty=1,bool ty2=1){
    x-=tag[v];
    auto ite=pos[v].lower_bound(x+2*tag[v]);
    if(ite!=pos[v].end()&&ty2)
    diff[v].push(II(ite->first-x,II(x,ite->first)));
    if(ty)
    neg[v][x]+=val;
}
void doit(int v,int d){
    while (!diff[v].empty()){
        auto tmp=diff[v].top().second;
        if(diff[v].top().first>(d+tag[v])*2) break;
        diff[v].pop();
        if(neg[v].find(tmp.first)==neg[v].end()) continue;
        if(pos[v].find(tmp.second)==pos[v].end()) continue;
        auto N=*neg[v].find(tmp.first);
        auto P=*pos[v].find(tmp.second);
        if(abs(N.second)>abs(P.second)){
            neg[v][N.first]+=P.second;
            pos[v].erase(P.first);
            add_neg(v,N.first+tag[v],N.second+P.second,0);
        }
        else{
            pos[v][P.first]+=N.second;
            neg[v].erase(N.first);
            add_pos(v,P.first-tag[v],N.second+P.second,0);
        }
    }
    tag[v]+=d;
}
int query(int now,int i){
    auto A=pos[now].find(i+tag[now]);
    int tmp=0;
    if(A!=pos[now].end()) tmp+=A->second;
    A=neg[now].find(i-tag[now]);
    if(A!=neg[now].end()) tmp+=A->second;
    return tmp;
}
void dfs(int now,int pre){
    for(auto it:g[now]) if(it.first!=pre){
        dfs(it.first,now);
        doit(it.first,it.second-1);
    }
    // cout<<now<<"_\n";
    // for(auto it:pos[2]) cout<<"+"<<it.first-tag[2]<<' '<<it.second<<endl;
    // for(auto it:neg[2]) cout<<"-"<<it.first+tag[2]<<' '<<it.second<<endl;
    for(auto it:g[now]) if(it.first!=pre){
        if(pos[it.first].size()+neg[it.first].size()>pos[now].size()+neg[now].size()){
            for(auto t:pos[now]) add_pos(it.first,t.first-tag[now],t.second);
            for(auto t:neg[now]) add_neg(it.first,t.first+tag[now],t.second);
            tag[now]=tag[it.first];
            pos[now].swap(pos[it.first]);
            neg[now].swap(neg[it.first]);
            diff[now].swap(diff[it.first]);
        }
        else{
            for(auto t:pos[it.first]) add_pos(now,t.first-tag[it.first],t.second);
            for(auto t:neg[it.first]) add_neg(now,t.first+tag[it.first],t.second);
        }
   }
//    if(now!=1){
        for(auto & it:event[now]){
            it.second-=max(0,max(-query(now,it.first),query(now,it.first+1)));
                // if(pos[now].find(it.first+tag[now])!=pos[now].end()) it.second-=pos[now][it.first+tag[now]];
                // if(neg[now].find(it.first+1-tag[now])!=neg[now].end()) it.second+=neg[now][it.first+1-tag[now]];
        }
        doit(now,1);
//    }
    for(auto it:event[now]){
        int x,v;
        x=it.first;
        v=it.second;
        if(v<=0) continue;
        add_pos(now,x,v);
        add_neg(now,x+1,-v);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rb(i,1,n-1){
        int u,v,l;
        cin>>u>>v>>l;
        l<<=1;
        g[u].PB(II(v,l));
        g[v].PB(II(u,l));
    }
    int k;
    cin>>k;
    rb(i,1,k){
        int d,f,p;
        cin>>d>>f>>p;
        d<<=1;
        event[p].PB(II(d,f));
    }
    g[0].PB(II(1,2));
    dfs(0,0);
    map<int,int> D;
    for(auto it:pos[0]) D[it.first-tag[1]]+=it.second;
    for(auto it:neg[0]) D[it.first+tag[1]]+=it.second;
    LL ans=0;
    LL tmp=0;
    for(auto it:D)
    tmp+=it.second,check_max(ans,tmp);
    cout<<ans<<endl;
    return 0;
}