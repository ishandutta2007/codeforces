/**
 *    author:  gary
 *    created: 31.05.2022 22:54:23
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
int fa[200000+10];
int root(int x){
    return fa[x]=(fa[x]==x? x:root(fa[x]));
}
void merge(int x,int y){fa[root(x)]=root(y);}
vector<mp> a[200000+10],e[200000+20];
void solve(){
    int n;
    cin>>n;
    rep(i,n) fa[i]=i;
    map<int,int> lsh;
    int cnt=0;
    vector<mp> seg(n);
    vector<int> col(n);
    rep(i,n){
        cin>>col[i]>>seg[i].first>>seg[i].second;
        lsh[seg[i].first]=lsh[seg[i].second]=1;
    }
    for(auto ite=lsh.begin();ite!=lsh.end();ite++)
    ite->second=++cnt;
    rb(i,0,cnt+1) a[i].clear(),e[i].clear();
    int id=0;
    for(auto &it:seg) it.first=lsh[it.first],it.second=lsh[it.second],a[it.first].PB(II(col[id],id)),e[it.second+1].PB(II(col[id],id)),id++;
    map<int,int> S[2];
    vector<mp> mem;
    rb(i,1,cnt){
        for(auto it:e[i]){
            it.second=root(it.second);
            S[it.first][it.second]--;
            if(S[it.first][it.second]==0) S[it.first].erase(it.second);
        }
        for(auto it:a[i]){
            S[it.first][it.second]++;
        }
        // cout<<i<<" "<<S[0].size()<<" "<<S[1].size()<<endl;
        if(S[0].size()&&S[1].size()){
            mem.emplace_back(S[0].begin()->first,S[1].begin()->first);
            rep(i,2){
                for(auto ite=S[i].begin();ite!=S[i].end();){
                    if(ite==S[i].begin()){
                        ++ite;
                        continue;
                    }
                    fa[ite->first]=S[i].begin()->first;
                    S[i].begin()->second+=ite->second;
                    ite=S[i].erase(ite);
                }
            }
        }
    }
    for(auto it:mem) merge(it.first,it.second);
    int ans=0;
    rep(i,n) ans+=root(i)==i;
    cout<<ans<<endl;
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