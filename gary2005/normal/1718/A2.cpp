/**
 *    author:  gary
 *    created: 19.08.2022 19:50:00
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,n) cin>>v[i];
    vector<int> pre;
    int sum=0;
    for(auto it:v){
        pre.push_back(sum);
        sum^=it;
    }
    pre.push_back(sum);
    map<int,int> las;
    vector<int> dp(pre.size(),0);
    rl(i,pre.size()-1,0){
        if(i!=pre.size()-1) dp[i]=dp[i+1];
        if(las.count(pre[i])) check_max(dp[i],dp[las[pre[i]]]+1);
        las[pre[i]]=i;
    }
    cout<<n-dp[0]<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}