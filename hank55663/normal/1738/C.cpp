
#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int cnt[2];
int dp[105][105][2][2];
int DP(int x,int y,int now,int op){
    if(dp[x][y][now][op]!=-1)return dp[x][y][now][op];
    if(x==0&&y==0){
        if(op==0){
            if(now==0)return 1;
            else return 0;
        }
        else{
            if(now==0)return 0;
            else return 1;
        }
    }
    dp[x][y][now][op]=0;
    if(op==0){
        dp[x][y][now][op]=(x?1-DP(x-1,y,now,1):0)|(y?1-DP(x,y-1,now^1,1):0);
    }
    else{
         dp[x][y][now][op]=(x?1-DP(x-1,y,now,0):0)|(y?1-DP(x,y-1,now,0):0);
    }
    return dp[x][y][now][op];
}
void solve(int T){
    MEM(cnt);
    MEMS(dp);
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        cnt[x&1]++;
    }
    if(DP(cnt[0],cnt[1],0,0))printf("Alice\n");
    else printf("Bob\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
       // cerr<<T<<endl;
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*
*/