/**
 *    author:  gary
 *    created: 11.12.2021 17:55:57
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
bool dp[100000+20];
int n;
pair<mp,int> a[100000+20];
mp mn[100000+20];
int mx[100000+20];
bool ans[100000+20];
void solve(){
    cin>>n;
    rb(i,1,n) dp[i]=false;
    rb(i,1,n) cin>>a[i].FIR.FIR;
    rb(i,1,n) cin>>a[i].FIR.SEC;
    rb(i,1,n) a[i].SEC=i;
    mn[n+1]=II(INF,INF);
    sort(a+1,a+1+n);
    rl(i,n,1) mn[i]=min(mn[i+1],II(a[i].FIR.SEC,i));
    mx[0]=-INF;
    rb(i,1,n) mx[i]=max(mx[i-1],a[i].FIR.SEC);
    dp[n]=1;
    rl(i,n-1,1){
        if(mx[i]>mn[i+1].FIR) dp[i]=dp[mn[i+1].SEC];
    }
    rb(i,1,n) ans[a[i].SEC]=dp[i];
    rb(i,1,n) cout<<ans[i];
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