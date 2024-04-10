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
int n;
LL a[50000+20];
LL pre[50000+20];
int can[50000+20];
int rc[50000+20];
int dp[50000+20];
void solve(){
    int x;
    cin>>n;
    rb(i,1,n) cin>>a[i];
    cin>>x;
    rb(i,1,n) pre[i]=pre[i-1]+a[i];
    rb(i,1,n) pre[i]-=1ll*i*x;
    deque<pair<LL,int> > dq;
    rb(i,1,n){
        if(i>=2){
            while(dq.size()&&dq.front().FIR<=pre[i-2]){
                dq.pop_front();
            }
            dq.push_front(II(pre[i-2],i-2));
        }
        auto ite=upper_bound(ALL(dq),II(pre[i],INF));
        if(ite!=dq.end()){
            can[i]=ite->SEC+1;   
        }
        else{
            can[i]=0;
        }
    }
    rb(i,1,n){
        rc[i]=rc[i-1];
        check_max(rc[i],i);
        while(rc[i]<n&&can[rc[i]+1]<i) rc[i]++;
    }

    memset(dp,0,sizeof(dp));

    rl(i,n,1){
        dp[i]=dp[i+1]+1;
        check_min(dp[i],dp[rc[i]+2]+(rc[i]!=n));
    }

    // cout<<"(";
    cout<<n-dp[1];
    // cout<<")";
    cout<<endl;
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