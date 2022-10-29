#include <bits/stdc++.h>

#define ll          long long
#define pb          emplace_back
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
int n,a[705];
bool ff[707][707];
bitset<701> is[707][707],dp[707][707];
bool sol(int l,int r,int x){
    if(l>r) return 1;
    if(is[l][r][x]) return dp[l][r][x];
    is[l][r][x]=1;
    rep(i,l,r+1){
        if(ff[i][x]==0) continue;
        if(sol(l,i-1,i) and sol(i+1,r,i)) return dp[l][r][x]=1;
    }
    return 0;
}
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>a[i];
    }
    rep(i,1,n+1){
        rep(j,1,n+1){
            if(__gcd(a[i],a[j])>1) ff[i][j]=1;
        }
    }
    rep(i,1,n+1){
        if(sol(1,i-1,i) and sol(i+1,n,i)){
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
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