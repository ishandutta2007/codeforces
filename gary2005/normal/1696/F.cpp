/**
 *    author:  gary
 *    created: 25.06.2022 22:27:29
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
bool same[101][101][101];
int fa[101];
bool c[101];
int id[101][101];
int n;
vector<int> solve_chain(vector<int> idx){
    if(idx.size()==1) return {idx[0]};
    if(idx.size()==2){
        return {idx[0],idx[1]};
    }
    vector<int> edges;
    rep(i,idx.size()){
        rb(j,0,n) c[j]=0;
        bool ok=1;
        rep(j,idx.size()){
            if(c[id[idx[i]][idx[j]]]){
                ok=0;
                break;
            }
            else{
                c[id[idx[i]][idx[j]]]=1;
            }
        }
        if(ok){
            int now=idx[i];
            swap(idx[i],idx.back());
            idx.pop_back();
            edges=solve_chain(idx);
            if(edges.empty()) return edges;
            if(same[now][edges[1]][edges[0]]){
                reverse(ALL(edges));
                edges.PB(now);
            }
            else{
                edges.PB(now);
            }
            break;
        }
    }
    return edges;
}
int root(int x){
    return fa[x]=(fa[x]==x? x:root(fa[x]));
}
void merge(int u,int v){
    fa[root(u)]=root(v);
}
vector<mp> edges;
void solve(vector<int> idx){
    if(idx.size()<=2){
        auto tmp=solve_chain(idx);
        rep(i,(int)(tmp.size())-1) edges.PB(II(tmp[i],tmp[i+1])),merge(tmp[i],tmp[i+1]);
        return;
    }
    bool ok=1;
    rep(i,idx.size()){
        if(root(idx[i])==root(idx[0])){
        }
        else ok=0;
    }
    if(ok) return;
    bool Ok=0;
    rep(i,idx.size()) {
        if(ok) return;
        rep(j,i){
        vector<int> tmp;
        for(auto it:idx) if(same[idx[i]][idx[j]][it]) tmp.PB(it);
        if(tmp.size()==idx.size()) return;
        if(tmp.size()>1){
            solve(tmp);
            Ok=1;
        }
        ok=1;
        rep(i,idx.size()) 
        if(root(idx[i])==root(idx[0])){
        }
        else ok=0;
        if(ok) return;
    }}
    if(!Ok){
        auto tmp=solve_chain(idx);
        rep(i,(int)(tmp.size())-1) edges.PB(II(tmp[i],tmp[i+1])),merge(tmp[i],tmp[i+1]);
    }
    rep(i,idx.size()) if(i) merge(idx[i],idx[i-1]);
}
int dis[101][101];
void solve(){
    cin>>n;
    rep(i,n) fa[i]=i;
    rep(i,n) rep(j,n) rep(k,n) same[i][j][k]=0;
    rb(i,1,n-1){
        rb(j,1,n-i){
            rb(k,1,n){
                char c;
                cin>>c;
                same[i-1][j+i-1][k-1]=same[j+i-1][i-1][k-1]=c-'0';
            }
        }
    }
    rep(i,n){
        int cnt=0;
        rep(j,n){
            bool ok=0;
            rep(k,j){
                if(same[j][k][i]){
                    ok=1;
                    id[i][j]=id[i][k];
                    break;
                }
            }
            if(!ok){
                id[i][j]=++cnt;
            }
        }
    }
    vector<int> v;
    rep(i,n) v.PB(i);
    edges.clear();
    solve(v);
    for(auto & it:edges) if(it.first>it.second) swap(it.first,it.second);
    sort(ALL(edges));
    edges.erase(unique(ALL(edges)),edges.end());
    if(edges.size()!=n-1){
        cout<<"No\n";
        return ;
    }
    rep(i,n) rep(j,n) dis[i][j]=INF;
    rep(i,n) dis[i][i]=0;
    for(auto it:edges) dis[it.first][it.second]=dis[it.second][it.first]=1;
    rep(k,n) rep(i,n) rep(j,n) check_min(dis[i][j],dis[i][k]+dis[k][j]);
    rep(i,n) rep(j,n) if(dis[i][j]==INF){
        cout<<"No\n";
        return ;
    }
    rep(i,n) rep(j,n) if(i!=j) rep(k,n) if((dis[i][k]==dis[j][k])!=same[i][j][k]){

        cout<<"No\n";
        return ;
    }
    cout<<"Yes\n";
    for(auto it:edges) cout<<it.first+1<<" "<<it.second+1<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}