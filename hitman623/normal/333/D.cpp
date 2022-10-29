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
int n,m,a[1001][1001],f[1001][1001];
bool check(int mid){
    memset(f,0,sizeof f);
    rep(i,0,n){
        vi v;
        rep(j,0,m){
            if(a[i][j]>=mid) v.pb(j);
        }
        rep(j,0,sz(v)){
            rep(k,j+1,sz(v)){
                f[v[j]][v[k]]++;
                if(f[v[j]][v[k]]>1) return 1;
            }
        }
    }
    return 0;
}
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        rep(j,0,m){
            cin>>a[i][j];
        }
    }
    int lo=0,hi=1e9+1;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(check(mid)) lo=mid;
        else hi=mid;
    }
    cout<<lo<<endl;
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