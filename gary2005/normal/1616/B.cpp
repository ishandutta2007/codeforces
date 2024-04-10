/**
 *    author:  gary
 *    created: 31.12.2021 21:05:37
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
    string s;
    cin>>s;
    string ans;
    bool equ=1;
    rep(i,n){
        if(i==0){
            ans.PB(s[i]);
            continue;
        }
        if(s[i]>ans.back()) break;
        ans.PB(s[i]);
    }
    if(ans.size()>1) equ=ans[0]==ans[1];
    if(equ){
        cout<<ans[0]<<ans[0]<<endl;
    }
    else{
        cout<<ans;
        reverse(ALL(ans));
        cout<<ans<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}