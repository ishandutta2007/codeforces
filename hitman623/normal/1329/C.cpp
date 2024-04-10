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
int h,g,a[1<<21],w[1<<21],inv[1<<21];
priority_queue<int> pq;
void dfs(int node){
    if(!a[2*node]) w[node]=node;
    else{
        dfs(2*node);
        dfs(2*node+1);
        if(a[2*node]>a[2*node+1]) w[node]=w[2*node];
        else w[node]=w[2*node+1];
    }
}
void go(int node){
    if(!a[2*node] and !a[2*node+1]) a[node]=0;
    else{
        if(a[2*node]>a[2*node+1]){
            a[node]=a[2*node];
            inv[a[node]]=node;
            go(2*node);
        }
        else{
            a[node]=a[2*node+1];
            inv[a[node]]=node;
            go(2*node+1);
        }
    }
    if(!a[2*node] and !a[2*node+1]) w[node]=node;
    else{
        if(a[2*node]>a[2*node+1]) w[node]=w[2*node];
        else w[node]=w[2*node+1];
    }
}
int v[1<<20];
void solve(){
    while(!pq.empty()) pq.pop();
    cin>>h>>g;
    a[1<<h]=0;
    rep(i,1,1<<h){
        cin>>a[i];
        inv[a[i]]=i;
        w[i]=0;
        a[i+(1<<h)]=0;
    }
    dfs(1);
    rep(i,1,1<<h) pq.push(a[i]);
    rep(i,0,(1<<h)-(1<<g)){
        while(w[inv[pq.top()]]<(1<<g)) pq.pop();
        int d=inv[pq.top()];
        pq.pop();
        go(d);
        v[i]=d;
    }
    ll sum=0;
    rep(i,1,1<<g) sum+=a[i];
    cout<<sum<<endl;
    rep(i,0,(1<<h)-(1<<g)) cout<<v[i]<<" ";
    cout<<endl;
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}