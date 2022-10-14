/**
 *    author:  gary
 *    created: 06.09.2022 22:26:18
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
int n,a[2002];
void solve(){
    int ans=-INF;
    cin>>n;
    rep(i,n) cin>>a[i];
    if(n==1){
        ans=0;
    }
    else{
        rep(i,n) check_max(ans,a[(i+n-1)%n]-a[i]);
        check_max(ans,*max_element(a+1,a+n)-a[0]);
        check_max(ans,a[n-1]-*min_element(a,a+n-1));
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}