/**
 *    author:  gary
 *    created: 24.11.2021 18:02:52
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
const int MAXN=6e5+1;
int n;
set<int> son[MAXN];
int sg[MAXN];
vector<int> g[MAXN];
int pre[MAXN];
void dfs(int now,int p){
    pre[now]=p;
    for(auto it:g[now]) if(it!=p) dfs(it,now),son[now].insert(it);
}
void calc(int now){
    for(auto ite=son[now].begin();ite!=son[now].end();ite++){
        calc(*ite);
        sg[now]^=sg[*ite]+1;
    }
}
int ro=1;
void ans(){
    if(sg[ro]==0) cout<<"2";
    else cout<<"1";
}
bool bad[MAXN];
void merge(vector<int> v){
    set<int> emp;
    for(auto it:v) bad[it]=1;
    rb(i,0,v.size()-2){
        son[v[i]].erase(v[i+1]);
        sg[v[i]]^=sg[v[i+1]]+1;
    }
    rb(i,1,v.size()-1){
        int now=v[i];
        if(son[now].size()>son[ro].size()){swap(now,ro);}
        for(auto ite=son[now].begin();ite!=son[now].end();ite++){
            pre[*ite]=ro;
            son[ro].insert(*ite);
            sg[ro]^=sg[*ite]+1;
        }
        son[now].swap(emp);
        emp.clear();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rb(i,1,n-1){
        int u,v;
        cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(1,0);
    calc(1);
    ans();
    int odn=n;
    rb(i,2,odn){
        if(bad[i]){
            ans();
            continue;
        }
        vector<int> chain;
        int now=i;
        while(now!=ro){
            chain.PB(now);
            now=pre[now];
        }
        chain.PB(ro);
        reverse(ALL(chain));
        if(chain.size()%2==0){
            son[ro].insert(++n);
            sg[n]=0;
            sg[ro]^=1;
        }
        merge(chain);
        ans();
    }
    return 0;
}