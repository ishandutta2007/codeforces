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
int n,d,p[30001];
bool is[30001][700];
int dp[30001][700];
int sol(int cur,int l){
    if(cur>30000) return 0;
    if(is[cur][l-d+300]) return dp[cur][l-d+300];
    int ans=0;
    if(cur+l-1>cur) ans=max(ans,sol(cur+l-1,l-1));
    if(cur+l>cur) ans=max(ans,sol(cur+l,l));
    if(cur+l+1>cur) ans=max(ans,sol(cur+l+1,l+1));
    is[cur][l-d+300]=1;
    return dp[cur][l-d+300]=ans+p[cur];
}
void solve(){
    cin>>n>>d;
    rep(i,0,n){
        int x;
        cin>>x;
        p[x]++;
    }
    cout<<sol(d,d)<<endl;
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