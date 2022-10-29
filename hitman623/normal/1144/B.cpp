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
int n;
vi odd,even;
void solve(){
    cin>>n;
    rep(i,0,n){
        int x;
        cin>>x;
        if(x%2) odd.pb(x);
        else even.pb(x);
    }
    sort(all(odd));
    sort(all(even));
    while(sz(odd) and sz(even)) odd.pop_back(),even.pop_back();
    if(sz(odd)) odd.pop_back();
    if(sz(even)) even.pop_back();
    int ans=0;
    for(auto i:odd) ans+=i;
    for(auto i:even) ans+=i;
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