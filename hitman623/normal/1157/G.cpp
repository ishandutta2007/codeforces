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
int n,m,col[202],row[202],a[202][202];
void check(){
    vi v;
    rep(i,0,n){
        rep(j,0,m){
            v.pb({a[i][j]^row[i]^col[j]});
        }
    }
    if(is_sorted(all(v))){
        cout<<"YES"<<endl;
        rep(i,0,n) cout<<row[i];
        cout<<endl;
        rep(i,0,m) cout<<col[i];
        cout<<endl;
        exit(0);
    }
}
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        rep(j,0,m){
            cin>>a[i][j];
        }
    }
    rep(l,0,m){
        rep(j,0,m) col[j]=!(a[0][j]^(j<l));
        rep(i,1,n) row[i]=!(a[i][0]^col[0]);
        check();
    }
    rep(l,1,n+1){
        rep(j,0,m) col[j]=a[0][j];
        rep(i,0,n) row[i]=!((a[i][0]^col[0])==(i>=l));
        check();
    }
    cout<<"NO"<<endl;
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