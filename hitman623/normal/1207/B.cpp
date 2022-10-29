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
int n,m,a[55][55];
void solve(){
    cin>>n>>m;
    rep(i,1,n+1){
        rep(j,1,m+1){
            cin>>a[i][j];
        }
    }
    vii v;
    rep(i,1,n+1){
        rep(j,1,m+1){
            if(a[i][j]==1){
                if(a[i][j]+a[i-1][j]+a[i][j-1]+a[i-1][j-1]==4) v.pb({i-1,j-1});
                else if(a[i][j]+a[i-1][j]+a[i][j+1]+a[i-1][j+1]==4) v.pb({i-1,j});
                else if(a[i][j]+a[i+1][j]+a[i][j-1]+a[i+1][j-1]==4) v.pb({i,j-1});
                else if(a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1]==4) v.pb({i,j});
                else{
                    cout<<-1<<endl;
                    return;
                }
            }
        }
    }
    sort(all(v));
    v.resize(unique(all(v))-v.begin());
    cout<<sz(v)<<endl;
    for(auto i:v) cout<<i.x<<" "<<i.y<<endl;
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