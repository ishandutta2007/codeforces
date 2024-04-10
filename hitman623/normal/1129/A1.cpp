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
vi v[5005];
void solve(){
    cin>>n>>m;
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        a--,b--;
        v[a].pb(b);
    }
    rep(i,0,n){
        int res=0;
        rep(j,0,n){
            int cur=(j+i)%n;
            int w=hell;
            for(auto k:v[cur]){
                w=min(w,j+(sz(v[cur])-1)*n+(k-cur+n)%n);
            }
            if(w<hell) res=max(res,w);
        }
        cout<<res<<" ";
    }
    cout<<endl;
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