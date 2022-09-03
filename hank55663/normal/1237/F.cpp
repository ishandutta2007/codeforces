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
#define hash Hash
int mod=998244353;
LL dp1[2][3605],dp2[2][3605];
LL dp[3605][3605];
int DP(int x,int y){
    if(x<0||y<0)return 0;
    if(x==0&&y==0)return 1;
    if(dp[x][y]!=-1)return dp[x][y];
    dp[x][y]=(DP(x-1,y)+DP(x-2,y-1))%mod;
    return dp[x][y];
}
LL fra[3605];
LL inv[3605];
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int row[3605],col[3605];
int main(){
    fra[0]=1;
    for(int i = 1;i<=3605;i++){
        fra[i]=fra[i-1]*i%mod;
        inv[i]=f_pow(fra[i],mod-2);
    }
    inv[0]=1;
    MEMS(dp);
    int h,w,n;
    scanf("%d %d %d",&h,&w,&n);
    for(int i = 0;i<n;i++){
        int r1,r2,c1,c2;
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
        row[r1]=row[r2]=1;
        col[c1]=col[c2]=1;
    }
    vector<int> v1,v2;
    int cnt=0;
    int tot1=0,tot2=0;
    for(int i = 1;i<=h;i++){
        if(row[i]){
            if(cnt){
                tot1+=cnt;
                v1.pb(cnt);
            }
            cnt=0;
        }
        else{
          //  printf("h %d\n",i);
            cnt++;
        }
    }
    if(cnt){
        v1.pb(cnt);
        tot1+=cnt;
    }
    cnt=0;
    for(int i=1;i<=w;i++){
        if(col[i]){
            if(cnt){
                tot2+=cnt;
                v2.pb(cnt);
            }
            cnt=0;
        }
        else{
            cnt++;
        }
    }
    if(cnt){
        v2.pb(cnt);
        tot2+=cnt;
    }
    int last1=1;
    dp1[1][0]=1;
    //vector<vector<int> > v1,v2;
    for(auto it:v1){
        fill(dp1[last1^1],dp1[last1^1]+3605,0);
        for(int j=0;j*2<=it;j++){
        LL tot=DP(it,j);    
            for(int k=0;(k+j)*2<=tot1;k++){
                dp1[last1^1][k+j]+=dp1[last1][k]*tot;
                dp1[last1^1][k+j]%=mod;
            }
        }
        last1^=1;
    }
    int last2=1;
    dp2[1][0]=1;
    //vector<vector<int> > v1,v2;
    for(auto it:v2){
         fill(dp2[last2^1],dp2[last2^1]+3605,0);
        for(int j=0;j*2<=it;j++){
            LL tot=DP(it,j);
            for(int k=0;(k+j)*2<=tot2;k++){
                dp2[last2^1][k+j]+=dp2[last2][k]*tot;
                dp2[last2^1][k+j]%=mod;
             //   printf("?%d %d\n",k+j,dp2[last2^1][k+j]);
            }
            //printf("%d\n",tot);
        }
        last2^=1;
      //  printf("%d %d\n",it,dp2[last2][0]);
    }
    LL ans=0;
    for(int i = 0;i<=tot1/2;i++){
        for(int j=0;j<=tot2/2;j++){
            if(tot1-i*2>=j&&tot2-j*2>=i){
                ans+=dp1[last1][i]*dp2[last2][j]%mod*fra[tot1-i*2]%mod*inv[tot1-i*2-j]%mod*fra[tot2-j*2]%mod*inv[tot2-j*2-i]%mod;
                ans%=mod;
             //  printf("%d %d %d %d %d %d %lld\n",i,j,dp1[last1][i],dp2[last2][j],tot1,tot2,ans);
            }
        }
    }
    printf("%lld\n",ans);
}