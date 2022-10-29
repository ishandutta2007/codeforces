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
int n;
ll a[7007],s;
int b[7007],deg[7007],vis[7007];
vi adj[7007];
void solve(){
    cin>>n;
    rep(i,1,n+1) cin>>a[i];
    rep(i,1,n+1){
        cin>>b[i];
        s+=b[i];
    }
    rep(i,1,n+1){
        rep(j,1,n+1){
            if(i==j) continue;
            if((a[i]&a[j])==a[i]){
                deg[i]++;
                adj[j].pb(i);
            }
        }
    }
    queue<int> q;
    rep(i,1,n+1) if(deg[i]==0) q.push(i);
    while(!q.empty()){
        int d=q.front();
        q.pop();
        if(vis[d]) continue;
        vis[d]=1;
        s-=b[d];
        for(auto j:adj[d]){
            deg[j]--;
            if(deg[j]==0){
                q.push(j);
            }
        }
    }
    cout<<s<<endl;
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