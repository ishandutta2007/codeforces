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
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,a[100005],f[100005],vis[100005],ans;
set<int> s;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        f[a[i]]++;
        s.insert(a[i]);
    }
    rep(i,0,n){
        f[a[i]]--;
        if(f[a[i]]==0) s.erase(a[i]);
        if(vis[a[i]]) continue;
        vis[a[i]]=1;
        ans+=sz(s);
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