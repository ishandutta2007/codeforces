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
int n,m,f[1001][6],a[1001];
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        string s;
        cin>>s;
        rep(j,0,m) f[j][s[j]-'A']++;
    }
    rep(i,0,m) cin>>a[i];
    int ans=0;
    rep(i,0,m){
        int mx=0;
        rep(j,0,5){
            mx=max(mx,f[i][j]);
        }
        ans+=mx*a[i];
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