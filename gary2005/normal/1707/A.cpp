/**
 *    author:  gary
 *    created: 16.07.2022 22:28:21
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
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1,0),b(n+1,0),c(n+1,0),ans(n+1,0);
    rb(i,1,n) cin>>a[i];
    int qq=0;
    rl(i,n,1){
        if(a[i]<=qq){
            ans[i]=1;
        }
        else if(qq<q){
            qq++;
            ans[i]=1;
        }
    }
    rb(i,1,n) cout<<ans[i];
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    cin>>T;
    while (T--)
    {
        solve();
    }
    return 0;
}