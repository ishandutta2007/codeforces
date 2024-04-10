#include <bits/stdc++.h>

#define int         long long
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
#define hell        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,q,s[200005],b[200005],cur=1,pos[200005],p[200005];
vi a[200005];
void dfs(int node){
    s[node]=1;
    b[cur++]=node;
    pos[node]=cur-1;
    for(auto i:a[node]){
        dfs(i);
        s[node]+=s[i];
    }
}
void solve(){
    cin>>n>>q;
    rep(i,2,n+1){
        cin>>p[i];
        a[p[i]].pb(i);
    }
    rep(i,1,n+1){
        sort(all(a[i]));
    }
    dfs(1);
    while(q--){
        int u,k;
        cin>>u>>k;
        if(s[u]<k) cout<<-1<<endl;
        else cout<<b[pos[u]+k-1]<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}