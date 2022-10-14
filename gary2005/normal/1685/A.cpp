/**
 *    author:  gary
 *    created: 26.05.2022 01:33:04
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
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
    vector<int> ans(n);
    rep(i,n) cin>>v[i];
    if(n&1){
        cout<<"NO\n";
        return ;
    }
    sort(ALL(v));
    rep(i,n/2){
        ans[i*2]=v[i];
    }
    rb(i,n/2,n-1){
        ans[(i-n/2)*2+1]=v[i];
    }
    bool ok=1;
    rep(i,n) ok&=((ans[i]<ans[(i+1)%n]&&ans[i]<ans[(i-1+n)%n])||(ans[i]>ans[(i+1)%n]&&ans[i]>ans[(i-1+n)%n]));
    if(ok){
        cout<<"YES\n";
        rep(i,n) cout<<ans[i]<<" ";
        cout<<endl;
    }
    else{
        cout<<"NO\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}