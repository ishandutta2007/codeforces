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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 1500
int main(){
    int n;
    scanf("%d",&n);
    pii p[200005];
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        p[i]=mp(x,i);
    }
    sort(p+1,p+n+1);
    int dp[200005];
    int from[200005];
    dp[0]=0;
    dp[1]=-1e9;
    dp[2]=-1e9;
    dp[3]=p[1].x;
    from[3]=0;
    for(int i =4;i<=n;i++){
        for(int j=i-3;j>=i-6&&j>=0;j--){
            if(dp[i]<dp[j]+p[j+1].x-p[j].x){
                dp[i]=dp[j]+p[j+1].x-p[j].x;
                from[i]=j;
            }
        }
    }
    int ans[200005];
    int now=n;  
    int cnt=1;
    while(now!=0){
        int x=from[now];
        for(int j=now;j>x;j--){
            ans[p[j].y]=cnt;
        }
        now=x;
        cnt++;
    }
    printf("%d %d\n",p[n].x-dp[n],cnt-1);
    for(int i = 1;i<=n;i++)
        printf("%d ",ans[i]);
    printf("\n");
}