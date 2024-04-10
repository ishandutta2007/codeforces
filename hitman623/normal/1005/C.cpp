#include <bits/stdc++.h>

#define ll          long long
#define pb          emplace_back
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
int n,x[200005],vis[200005],ans;
unordered_map<int,vi> mp;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>x[i];
        mp[x[i]].pb(i);
    }
    rep(i,0,n){
        if(vis[i]) continue;
        int cur=1,f=0;
        rep(j,0,31){
            if(mp.count(cur-x[i]) and (sz(mp[cur-x[i]])>1 || mp[cur-x[i]][0]!=i)){
                vis[i]=1;
                for(auto k:mp[cur-x[i]]){
                    vis[k]=1;                    
                }
                f=1;
                break;
            }
            cur*=2;
        }
        if(!f) ans++;
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