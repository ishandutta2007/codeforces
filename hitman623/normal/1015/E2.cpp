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
int n,m,vis[1001][1001];
string a[1002];
vector<pair<pii,int>> res;
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        rep(j,0,m){
            if(a[i][j]=='*'){
                int d=min({i,j,n-i-1,m-j-1}),ans=0;
                rep(k,1,d+1){
                    if(a[i][j+k]=='.' or a[i+k][j]=='.' or a[i-k][j]=='.' or a[i][j-k]=='.') break;
                    vis[i][j+k]=vis[i+k][j]=vis[i-k][j]=vis[i][j-k]=1;
                    ans=k;
                }
                if(ans) res.pb({{i+1,j+1},ans}),vis[i][j]=1;
            }
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            if(a[i][j]=='*' and !vis[i][j]){
                cout<<-1<<endl;
                return;
            }
        }
    }
    cout<<sz(res)<<endl;
    for(auto i:res){
        cout<<i.x.x<<" "<<i.x.y<<" "<<i.y<<endl;
    }
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