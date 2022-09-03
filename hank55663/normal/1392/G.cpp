#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int dp[21][1<<20];
pii p[1000005];
void solve(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    char c[25],c2[25];
    char c3[25];
    int val[25];
    scanf("%s %s",c+1,c2+1);
    for(int i = 1;i<=k;i++)c3[i]=c[i];
    for(int i = 1;i<=k;i++)val[i]=i;
    for(int i = 1;i<=n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        p[i]=mp(a,b);
        swap(val[a],val[b]);
        int sum=0;
        for(int j = 1;j<=k;j++){
            if(c[val[j]]==c2[j])sum+=(1<<(val[j]-1));
        }
        dp[0][sum]=i;
    }
    for(int j = 1;j<=k;j++){
        for(int i = 0;i<(1<<k);i++){
            for(int a = 0;a<k;a++){
                dp[j][i]=max(dp[j][i],dp[j-1][i^(1<<a)]);
            }
          //  printf("%d ",dp[i][j]);
        }
      //  printf("\n");
    }
    int Max=-1,Maxl=0,Maxr=0;
    int loc[25];
    for(int i = 1;i<=k;i++)loc[i]=i;
    for(int i = 1;i<=n;i++){
        int val=0;
        for(int j = 1;j<=k;j++)if(c[j]!=c3[loc[j]])val+=(1<<(loc[j]-1));
       // printf("%d\n",val);
        for(int j = 0;j<=k;j++){
            //printf("%d %d %d %d\n",i,j,dp[((1<<k)-1)^val][j],i+m-1);
            if(dp[j][((1<<k)-1)^val]>=i+m-1){
                if((k-j)>Max){
                    Max=k-j;
                    Maxl=i;
                    Maxr=dp[j][((1<<k)-1)^val];
                }
            }
        }
        swap(loc[p[i].x],loc[p[i].y]);
    }
    printf("%d\n%d %d\n",Max,Maxl,Maxr);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/