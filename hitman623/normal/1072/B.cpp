#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
struct Two_SAT{
    int N;
    vi vis,comp,assignment;
    vector<vi> adj,revadj;
    stack<int> stk;
    Two_SAT(int n){
        N=n;
        vis.resize(2*N+1);
        comp.resize(2*N+1);
        adj.resize(2*N+1);
        revadj.resize(2*N+1);
        assignment.resize(2*N+1);
    }
    void add_edge(int u,int v){
        adj[u].pb(v);
        revadj[v].pb(u);
    }
    void dfs(int node){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){                
                dfs(i);
            }    
        }
        stk.push(node);
    }
    void revdfs(int node,int cur_comp){
        comp[node]=cur_comp;
        for(auto i:revadj[node]){
            if(!comp[i]){
                revdfs(i,cur_comp);
            }
        }
    }
    bool is_sat(){
        rep(i,1,2*N+1){
            if(!vis[i]){
                dfs(i);
            }
        }
        int curcomp=1;
        while(!stk.empty()){
            int cur=stk.top();
            stk.pop();
            if(!comp[cur]){
                revdfs(cur,curcomp);
                curcomp++;
            }
        }
        rep(i,1,N+1){
            if(comp[i]==comp[i+N]) return false;
            assignment[i]=comp[i]>comp[i+N];
        }
        return true;
    }
};
int n,a[100005],b[100005];
void solve(){
    cin>>n;
    Two_SAT o1(n),o2(n);
    rep(i,1,n){
        cin>>a[i];
        if(a[i]&1){
            o1.add_edge(i+n,i+1);
            o1.add_edge(i+1+n,i);
        }
        else{
            o1.add_edge(i,i+n);
            o1.add_edge(i+1,i+1+n);
        }
        if(a[i]&2){
            o2.add_edge(i+n,i+1);
            o2.add_edge(i+1+n,i);
        }
        else{
            o2.add_edge(i,i+n);
            o2.add_edge(i+1,i+1+n);
        }
    }  
    rep(i,1,n){
        cin>>b[i];
        if(b[i]&1){
            o1.add_edge(i+n,i);
            o1.add_edge(i+1+n,i+1);
        }
        else{
            o1.add_edge(i,i+1+n);
            o1.add_edge(i+1,i+n);
        }
        if(b[i]&2){
            o2.add_edge(i+n,i);
            o2.add_edge(i+1+n,i+1);
        }
        else{
            o2.add_edge(i,i+n+1);
            o2.add_edge(i+1,i+n);
        }
    }
    if(o1.is_sat() and o2.is_sat()){
        cout<<"YES"<<endl;
        rep(i,1,n+1){
            cout<<o1.assignment[i]+2*o2.assignment[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}