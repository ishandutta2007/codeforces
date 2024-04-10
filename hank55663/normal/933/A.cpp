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
int cnt[2005][2];
int pre[2005];
int suf[2005];
int main(){
    int n;
    scanf("%d",&n);
    int a[2005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[i][0]=cnt[i-1][0];
        cnt[i][1]=cnt[i-1][1];
        cnt[i][a[i]-1]++;
    }
    for(int i = 1;i<=n;i++){
        pre[i]=0;
        for(int j=0;j<=i;j++){
            pre[i]=max(pre[i],cnt[j][0]+cnt[i][1]-cnt[j][1]);
        }
    }
    for(int i = n;i>=1;i--){
        suf[i]=0;
        for(int j=n;j>=i-1;j--){
            suf[i]=max(suf[i],cnt[n][1]-cnt[j][1]+cnt[j][0]-cnt[i-1][0]);
          //  if(i==n){
           //     printf("%d %d %d %d\n",i,j,cnt[n][1]-cnt[j][1],cnt[j-1][0]+cnt[i-1][0]);
           // }
        }
    }
    int ans=0;
    for(int i = 0;i<=n;i++){
     //   printf("%d %d\n",pre[i],suf[i+1]);
        ans=max(ans,pre[i]+suf[i+1]);
    }
    printf("%d\n",ans);
}