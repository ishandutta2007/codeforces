#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          unordered_map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,r[5005][5005],ans;
string a[5005];
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        for(int j=m-1;j>=0;j--){
            if(a[i][j+1]<='0') r[i][j]=j;
            else r[i][j]=r[i][j+1];
        }
    }
    rep(i,0,m){
        vi v;
        rep(j,0,n){
            if(a[j][i]=='0') continue;
            v.pb(r[j][i]-i+1);
        }
        sort(all(v));
        rep(j,0,sz(v)){
            ans=max(ans,(sz(v)-j)*v[j]);
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