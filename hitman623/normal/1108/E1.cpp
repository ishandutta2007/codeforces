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
int n,m,l[303],r[303],a[303];
pii ans;
int res=-hell;
void solve(){
    cin>>n>>m;
    rep(i,1,n+1) cin>>a[i];
    rep(i,1,m+1) cin>>l[i]>>r[i];
    rep(i,1,n+1){
        rep(j,1,n+1){
            int mx=a[i];
            int mn=a[j];
            rep(k,1,m+1){
                bool f1=0,f2=0;
                if(l[k]<=i and i<=r[k]) f1=1;
                if(l[k]<=j and j<=r[k]) f2=1;
                if(f1 and f2) continue;
                if(f2) mn--;
            }
            if(res<mx-mn){
                res=mx-mn;
                ans={i,j};
            }
        }
    }
    vi w;
    rep(k,1,m+1){
        bool f1=0,f2=0;
        if(l[k]<=ans.x and ans.x<=r[k]) f1=1;
        if(l[k]<=ans.y and ans.y<=r[k]) f2=1;
        if(f1 and f2) continue;
        if(f2){
            w.pb(k);
        }
    }
    cout<<res<<endl;
    cout<<sz(w)<<endl;
    for(auto i:w) cout<<i<<" ";
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