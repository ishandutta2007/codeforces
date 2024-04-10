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
int n,vis[1001],done[1001],ans;
string a[1001],b[1001];
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        cin>>b[i];
    }
    rep(i,0,n){
        rep(j,0,n){
            if(a[i]==b[j] and vis[j]==0){
                vis[j]=1;
                done[i]=1;
                break;
            }
        }
    }
    rep(i,0,n){
        if(done[i]) continue;
        rep(j,0,n){
            if(vis[j]) continue;
            if(sz(a[i])!=sz(b[j])) continue;
            rep(k,0,sz(a[i])){
                if(a[i][k]!=b[j][k]){
                    ans++;
                }
            }
            vis[j]=1;
            done[i]=1;
            break;
        }
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