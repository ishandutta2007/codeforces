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
int n,k;
mi vis;
queue<int> q;
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        int x;
        cin>>x;
        if(vis[x]);
        else if(sz(q)<k){
            q.push(x);
            vis[x]=1;
        }
        else{
            int d=q.front();
            vis[d]=0;
            q.pop();
            q.push(x);
            vis[x]=1;
        }
    }
    vi v;
    while(!q.empty()){
        v.pb(q.front());
        q.pop();
    }
    reverse(all(v));
    cout<<sz(v)<<endl;
    for(auto i:v) cout<<i<<" ";
    cout<<endl;
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