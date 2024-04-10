/**
 *    author:  gary
 *    created: 16.06.2022 22:23:56
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
    vector<LL> v(n),a(n,0);
    LL sum=0;
    rep(i,n) cin>>v[i],sum+=v[i];
    if(sum!=0){
        cout<<"no\n";
        return ;
    }
    bool havezero=0;
    rep(i,n-1){
        if(v[i]<a[i]){
            cout<<"no\n";
            return;
        }
        if(v[i]==a[i]) havezero=1;
        if(v[i]>a[i]){
            if(havezero){
                cout<<"no\n";
                return ;
            }
            a[i+1]-=v[i]-a[i];
            a[i]+=v[i]-a[i];
        }
    }
    cout<<"yes\n";
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