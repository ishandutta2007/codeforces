/**
 *    author:  gary
 *    created: 22.03.2022 22:28:55
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
const int MOD=998244353;
int dp[255][255];
int quick[255][255*255];
int comb[255][255];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    rb(i,1,250){
        quick[i][0]=1;
        rb(j,1,250*250) quick[i][j]=1ll*quick[i][j-1]*i%MOD;
    }
    rb(i,0,250) comb[i][0]=1;
    rb(i,1,250) rb(j,1,250) (comb[i][j]=comb[i-1][j]+comb[i-1][j-1])%=MOD;
    dp[0][0]=1;
    rb(i,0,k-1){
        rb(j,0,n-1){
            if(dp[i][j]){
                rb(z,0,n-1-j){
                    int coef1;
                    coef1=quick[i+1][z*(z-1)/2+z*(n-1-j-z)];
                    (dp[i+1][j+z]+=1ll*dp[i][j]*coef1%MOD*comb[n-1-j][z]%MOD)%=MOD;
                }
            }
        }
    }
    cout<<dp[k][n-1]<<endl;
    return 0;
}