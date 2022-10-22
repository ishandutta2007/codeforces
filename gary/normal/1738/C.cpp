/**
 *    author:  gary
 *    created: 30.09.2022 22:31:53
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
bool dp[101][101][2][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rb(i,0,100) rb(j,0,100) rep(k,2) rep(turn,2){
        if(i+j==0){
            dp[i][j][k][turn]=(k==0);
        }
        else{
            if(i){
                if(turn==0) dp[i][j][k][turn]|=dp[i-1][j][k][1];
                else dp[i][j][k][turn]|=!dp[i-1][j][k][0];
            }
            if(j){
                if(turn==0) dp[i][j][k][turn]|=dp[i][j-1][k^1][1];
                else dp[i][j][k][turn]|=!dp[i][j-1][k][0];
            }
            if(turn==1) dp[i][j][k][turn]^=1;
        }
    }
    // cout<<dp[0][2][1][1]<<endl;
    while (t--){
        int n;
        int a=0,b=0;
        cin>>n;
        rep(i,n){
            int x;
            cin>>x;
            if(abs(x)%2) b++;
            else a++;
        }
        cout<<(dp[a][b][0][0]? "Alice":"Bob")<<endl;
    }
    return 0;
}