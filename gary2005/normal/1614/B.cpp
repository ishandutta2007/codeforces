/**
 *    author:  gary
 *    created: 26.11.2021 19:02:03
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
int n,a[200000+20],x[200000+20];
mp b[200000+20];
void solve(){
    cin>>n;
    rb(i,1,n) cin>>a[i],b[i]=II(a[i],i);
    sort(b+1,b+1+n);
    reverse(b+1,b+1+n);
    int l=0,r=0;
    rb(i,1,n){
        if(i&1) x[b[i].SEC]=--l;
        else x[b[i].SEC]=++r;
    }
    LL ans=0;
    rb(i,1,n){
        ans+=2ll*abs(x[i]-x[0])*a[i];
    }
    cout<<ans<<endl;
    rb(i,0,n){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}