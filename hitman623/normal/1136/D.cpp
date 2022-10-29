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
vi p,a[300005];
void solve(){
    cin>>n>>m;
    p.resize(n);
    rep(i,0,n) cin>>p[i];
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
    }
    rep(i,1,n+1) sort(all(a[i]));
    for(int i=n-2;i>=0;i--){
        int f=1;
        rep(j,i+1,sz(p)){
            if(!binary_search(all(a[p[i]]),p[j])){
                f=0;
                break;
            }
        }
        if(f) p.erase(p.begin()+i);
    }
    cout<<n-sz(p)<<endl;
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