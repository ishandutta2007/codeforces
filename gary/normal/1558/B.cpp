/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=4e6+5;
int MOD;
int n;
int dp[MAXN];
int suf[MAXN];
void add(int & A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
int main(){
    cin>>n>>MOD;
    dp[n]=1;
    suf[n]=1;
    rl(i,n-1,1){
        dp[i]=suf[i+1];
        for(int y=2;;y++){
            if(y*i>n) break;
            add(dp[i],suf[y*i]);
            if(y*(i+1)<=n)
            add(dp[i],MOD-suf[y*(i+1)]);
        }
        suf[i]=suf[i+1];
        add(suf[i],dp[i]);
    }
    cout<<dp[1]<<endl;
    return 0;
}