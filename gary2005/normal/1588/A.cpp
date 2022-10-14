/**
 *    author:  gary
 *    created: 14.11.2021 14:01:21
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
const int MAXN=101;
int a[MAXN],b[MAXN],n;
void solve(){
    cin>>n;
    rb(i,1,n) cin>>a[i];
    rb(i,1,n) cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    bool ok=1;
    rl(i,n,1){
        if(b[i]==a[i]||b[i]==a[i]+1);
        else ok=0;
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}