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
int par[200005],r[200005];
int find_par(int node){
    if(node==par[node]) return node;
    else return par[node]=find_par(par[node]);
}
void merge(int u,int v){
    u=find_par(u);
    v=find_par(v);
    if(u==v) return;
    par[v]=u;
    r[v]=max(r[v],r[u]);
    r[u]=max(r[u],r[v]);
}
int n,m;
void solve(){
    cin>>n>>m;
    rep(i,1,n+1) r[i]=par[i]=i;
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        merge(x,y);
    }
    int cur=1,ans=0;
    set<int> st;
    rep(i,1,n+1){
        st.insert(find_par(i));
        cur=max(cur,r[find_par(i)]);
        if(cur==i){
            ans+=sz(st)-1;
            cur=i+1;
            st.clear();
        }
    }
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