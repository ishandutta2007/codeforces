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
int n,q,h[200005],ent[200005],ext[200005],tim,p[200005];
vi a[200005];
void dfs(int node,int pa){
    ent[node]=++tim;
    h[node]=h[pa]+1;
    p[node]=pa;
    for(auto i:a[node]){
        if(i!=pa){
            dfs(i,node);
        }
    }
    ext[node]=tim;
}
void solve(){
    cin>>n>>q;
    rep(i,0,n-1){
        int u,v;
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
    dfs(1,1);
    while(q--){
        int k;
        vi v;
        cin>>k;
        v.resize(k);
        rep(i,0,k){
            cin>>v[i];
            v[i]=p[v[i]];
        }
        sort(all(v));
        v.resize(unique(all(v))-v.begin());
        sort(all(v),[](int x,int y){
            return h[x]<h[y];
        });
        int cur=v[0],f=1;
        rep(i,1,sz(v)){
            if(ent[cur]<=ent[v[i]] and ext[v[i]]<=ext[cur]);
            else f=0;
            cur=v[i];
        }
        if(f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

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