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
#define KK 500
#define N 100005
char c[1000005];
pll dp[1000005];
pll cal(int n,int l,int cost,int u){
    for(int i = 0;i<=n;i++)
        dp[i]=mp(0,0);
   // fill(dp,dp+n+1,mp(0ll,0ll));
    for(int i = 1;i<=n;i++){
        if(u){
            if(c[i]>='A'&&c[i]<='Z'){
                pll p1=dp[i-1];
                pll p2=dp[max(i-l,0)];
                p1.x++;
                p2.x+=cost;
                p2.y++;
                dp[i]=min(p1,p2);
            }
            else{
                pll p1=dp[i-1];
                pll p2=dp[max(i-l,0)];
               // p1.x++;
                p2.x+=cost;
                p2.y++;
                dp[i]=min(p1,p2);
            }
        }
        else{
            if(c[i]>='a'&&c[i]<='z'){
                pll p1=dp[i-1];
                pll p2=dp[max(i-l,0)];
                p1.x++;
                p2.x+=cost;
                p2.y++;
                dp[i]=min(p1,p2);
            }
            else{
                pll p1=dp[i-1];
                pll p2=dp[max(i-l,0)];
                //p1.x++;
                p2.x+=cost;
                p2.y++;
                dp[i]=min(p1,p2);
            }
        }
    }
    return dp[n];
}
int main(){
    int n,k,l;
    scanf("%d %d %d",&n,&k,&l);
    scanf("%s",c+1);
    int u=0,d=0;
    for(int i=1;i<=n;i++){
        if(c[i]>='A'&&c[i]<='Z')u=1;
        else d=1;
    }
    if(!u&&!d){
        printf("0\n");
        return 0;
    }
    int Max=1e9,Min=-1;
    LL ans=n;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        pll p=cal(n,l,mid,0);
        //printf("%lld %lld %lld\n",p.x,p.y,mid);
        if(p.y<=k){
            Max=mid;
            ans=min(ans,p.x-p.y*mid);
        }
        else{
            Min=mid;
        }
    }
    if(ans==0){
        printf("0\n");
        return 0;
    }
    {
    pll p1=cal(n,l,Min,0);
    pll p2=cal(n,l,Max,0);
    LL ans1=p1.x-p1.y*Min;
    LL ans2=p2.x-p2.y*Max;
    ans=min((ans1*(k-p2.y)+ans2*(p1.y-k))/(p1.y-p2.y),ans);
   // printf("%lld %lld %lld %lld\n",ans1,ans2,p1.y,p2.y);
    //printf("%lld\n",(ans1*(k-p2.y)+ans2*(p1.y-k))/(p1.y-p2.y));
    }
    /*
    0 3 0  0,3 1 2,1
    3 1 1
    */
    Max=1e9,Min=-1;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        pll p=cal(n,l,mid,1);
     //    printf("%lld %lld %lld\n",p.x,p.y,mid);
        if(p.y<=k){
            Max=mid;
            ans=min(ans,p.x-p.y*mid);
        }
        else{
            Min=mid;
        }
    }
    if(ans==0){
        printf("0\n");
        return 0;
    }
    {
    pll p1=cal(n,l,Min,1);
    pll p2=cal(n,l,Max,1);
    LL ans1=p1.x-p1.y*Min;
    LL ans2=p2.x-p2.y*Max;
    ans=min((ans1*(k-p2.y)+ans2*(p1.y-k))/(p1.y-p2.y),ans);
   // printf("%lld %lld %lld %lld\n",ans1,ans2,p1.y,p2.y);
   // printf("%lld\n",(ans1*(k-p2.y)+ans2*(p1.y-k))/(p1.y-p2.y));
    }
    if(ans==0){
        printf("0\n");
        return 0;
    }
    printf("%lld\n",ans);
}