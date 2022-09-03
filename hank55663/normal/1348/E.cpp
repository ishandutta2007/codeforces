#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 262144
LL dp[505][505];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    MEM(dp);
    dp[0][0]=1;
    LL tot=0;
    for(int i = 1;i<=n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        tot+=a;
        tot+=b;
        for(int j=0;j<k&&j<=a;j++){
            int needb=(k-(a-j)%k)%k;
            if(needb>b)continue;
           // printf("! %d\n",needb);
            for(int x=0;x<k;x++){
                if(dp[i-1][x]){
                    dp[i][(x+j)%k]=1;
                //    printf("%d %d\n",i,(x+j)%k);
                }
            }
        }
    }
    LL ans=0;
    for(int i = 0;i<k;i++){
        if(dp[n][i]){
            ans=max(ans,(tot-i)/k);
        }
    }
    printf("%lld\n",ans);
}