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
int n,m;
vi fa[2002],fb[2002];
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        rep(j,0,m){
            int x;
            cin>>x;
            fa[j+i].pb(x);
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            int x;
            cin>>x;
            fb[j+i].pb(x);
        }
    }
    rep(i,0,n+m){
        sort(all(fa[i]));
        sort(all(fb[i]));
        if(fa[i]!=fb[i]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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