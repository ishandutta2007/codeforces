/**
 *    author:  gary
 *    created: 27.03.2022 22:29:41
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
int n,c[100000+10];
void solve(){
    cin>>n;
    rb(i,1,n) cin>>c[i];
    vector<int> v;
    rb(i,1,n){
        if(c[i]==1){
            if(v.size()){
            cout<<"NO\n";
            return;
            }
            rb(j,i,n) v.PB(c[j]);
            rb(j,1,i-1) v.PB(c[j]);
        }
    }
    if(v.empty()){
        cout<<"NO\n";
        return;
    }
    rep(i,v.size()){
        if(i&&v[i]>v[i-1]+1){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    return;
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