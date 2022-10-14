/**
 *    author:  gary
 *    created: 12.12.2021 23:09:13
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
int a[200000+20];
int dp[200000+20][2];
const int MOD=998244353;
void add(int & A,int B){
    (A+=B);
    if(A>=MOD) A-=MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rb(i,1,n) cin>>a[i];
    stack<pair<int,mp> > sta;
    dp[0][0]=1;
    int s[2]={0,0};
    rb(i,1,n){
        pair<int,mp> now;
        now.FIR=a[i];
        now.SEC=II(dp[i-1][0],dp[i-1][1]);
        while(!sta.empty()&&sta.top().FIR>now.FIR){
            auto tmp=sta.top();
            sta.pop();
            add(s[0],MOD-1ll*tmp.FIR*tmp.SEC.FIR%MOD);
            add(s[1],MOD-1ll*tmp.FIR*tmp.SEC.SEC%MOD);
            add(now.SEC.FIR,tmp.SEC.FIR);
            add(now.SEC.SEC,tmp.SEC.SEC);
        }
        add(s[0],1ll*now.FIR*now.SEC.FIR%MOD);
        add(s[1],1ll*now.FIR*now.SEC.SEC%MOD);
        sta.push(now);
        dp[i][0]=s[1];
        dp[i][1]=s[0];
    }
    int answer=(dp[n][n&1]-dp[n][(n&1)^1]+MOD)%MOD;
    cout<<answer<<endl;
    return 0;
}