#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
using namespace std;

int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n;
        scanf("%d",&n);
        double c,t;
        scanf("%lf %lf",&c,&t);
        pii p[105];
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            p[i]=mp(x,y);
        }
        sort(p,p+n);
        reverse(p,p+n);
        double dp[105][1005];
        for(int i=0;i<105;i++)
            for(int j=0;j<1005;j++)
                dp[i][j]=1e12;
        dp[0][0]=0;
        double hi[105];
        hi[0]=10.0/9;
        for(int i=1;i<=n;i++)
        hi[i]=hi[i-1]*10/9;
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                for(int k=0;k<=10*i;k++){
                    dp[j+1][k+p[i].y]=min(dp[j][k]+p[i].x*hi[j],dp[j+1][k+p[i].y]);
                  //  printf("%d %d %f\n",j+1,k+p[i].y,dp[j+1][k+p[i].y]);
                }
            }
        }
        //x/(1+t*c)+t
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int k=1;k<=1000;k++){
                if(dp[i][k]>1e11)continue;
               // printf("%d %d %f\n",i,k,dp[i][k]);
                double tot=t-i*10;
                if(tot<0)
                continue;
                double Max=tot,Min=0;
                double x=dp[i][k];
                for(int tt=0;tt<30;tt++){
                    double mid=(Max+Min)/2;
                    double value1=x/(1+mid*c)+mid;
                    mid+=1e-4;
                    double value2=x/(1+mid*c)+mid;
                    if(value2<value1){
                        Min=mid;
                    }
                    else{
                        Max=mid;
                    }
                  //  printf("%f %f %f\n",mid,value1,value2);
                }
               // printf("%f %f\n",Max,x/(1+Max*c)+Max+i*10);
               // system("PAUSE");
                if(tot>x/(1+Max*c)+Max){
                    ans=max(ans,k);
                }
            }
        }
        printf("%d\n",ans);
    }
}