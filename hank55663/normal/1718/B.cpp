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
int dp[500005];
void solve(){
    int n;
    scanf("%d",&n);
    int c[105];
    LL sum=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&c[i]);
        sum+=c[i];
    }
    if(n==1){
        if(c[0]==1)printf("YES\n");
        else printf("NO\n");
        return;
    }
    if(n==2&&c[0]==1&&c[1]==1){
        printf("YES\n");
        return;
    }
    int dp[55];
    dp[1]=1;
    dp[2]=1;
    sum-=2;
    for(int i = 3;;i++){
        dp[i]=dp[i-1]+dp[i-2];
        //printf("%d ",dp[i]);
        sum-=dp[i];
        if(sum==0){
           // reverse(dp+1,dp+i+1);
            priority_queue<pii> pq;
            for(int j=0;j<n;j++)pq.push(mp(c[j],i+10));
            for(int j=i;j>=1;j--){
                pii p=pq.top();
                pq.pop();
                if(p.x<dp[j]){
                    printf("NO\n");
                    return;
                }
                if(p.y==j+1){
                    printf("NO\n");
                    return;
                }
                p.x-=dp[j];
                if(p.x)pq.push(mp(p.x,j));
            }
            if(pq.empty()){
                printf("YES\n");
                return;
            }
        }
        else if(sum<0){
            printf("NO\n");
            return;
        }
        if(dp[i]>1e9){
            printf("NO\n");
            return;
        }
    }
    
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}

/*
*/