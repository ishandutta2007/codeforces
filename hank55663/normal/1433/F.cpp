#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int dp[80][80];

    for(int i = 0;i<80;i++){
        for(int j =0;j<80;j++){
            dp[i][j]=-1e9;
        }
    }
    dp[0][0]=0;
    for(int i = 0;i<n;i++){
        vector<int> v;
        for(int j = 0;j<m;j++){
            int x;
            scanf("%d",&x);
            v.pb(x);
        }
        int Max[80][80];
     
        for(int j=0;j<80;j++){
            for(int a = 0;a<80;a++){
                Max[j][a]=-1e9;
            }
        }
           Max[0][0]=0;
        for(auto it:v){
            for(int j=79;j>=0;j--){
                for(int a = 0;a<k;a++){
                    Max[j+1][(a+it)%k]=max(Max[j+1][(a+it)%k],Max[j][a]+it);
                }
            }
        }
       // int Max[100];
       for(int j=0;j<=m/2;j++){
            for(int a=0;a<k;a++){
                if(Max[j][a]>=0){
                for(int b=0;b<k;b++){
                    dp[i+1][(b+a)%k]=max(dp[i+1][(b+a)%k],dp[i][b]+Max[j][a]);
                }
               // printf("%d ",Max[j][a]);
                }
               // printf("\n");
            }
        }
    }
    printf("%d\n",dp[n][0]);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    int n;
    while(t--){
        solve();
    }
}
/*
32 16 15 20 13 2 1
16 8 25 30 10 0 0
5 6 30 24 16 1 1
18 21 39 12 30 1 1
10 8 29 13 36 1 1
24 25 30 31 3 0 0
21 22 10 27 33 0 0
*/