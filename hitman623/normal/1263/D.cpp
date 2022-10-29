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
int par[200005],s[200005];
int fp(int node){
    if(node==par[node]) return node;
    else return par[node]=fp(par[node]);
}
void merge(int u,int v){
    u=fp(u);
    v=fp(v);
    if(u==v) return;
    par[v]=u;
    s[u]+=s[v];
    s[v]=0;
}
int n;
vi v[26];
void solve(){
    cin>>n;
    rep(i,1,n+1){
        par[i]=i;
        s[i]=1;
        string e;
        cin>>e;
        for(auto j:e) v[j-'a'].pb(i);
    }
    rep(i,0,26){
        if(sz(v[i])==0) continue;
        int cur=v[i][0];
        for(auto j:v[i]) merge(cur,j);
    }
    int ans=0;
    rep(i,1,n+1) ans+=(s[i]>0);
    cout<<ans<<endl;
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