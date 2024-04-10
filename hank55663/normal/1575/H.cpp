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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int dp[2][505][505];
int cnt[505][505];
char a[505],b[505];
int f[505];
int go[505][2];
void KMP(char *c){
    int j=-1;
    f[0]=-1;
    for(int i = 1;c[i]!=0;i++){
        while(j!=-1&&c[i]!=c[j+1])j=f[j];
        if(c[i]==c[j+1])j++;
        f[i]=j;
    }
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    scanf("%s %s",a,b);
    for(int i = 0;i<2;i++){
        for(int j = 0;j<=n;j++){
            for(int k = 0;k<=m;k++){
                dp[i][j][k]=1e9;
            }
        }
    }
        KMP(b);
    for(int i = 0;i<m;i++){
        int now=i;
        while(now!=-1&&b[now+1]!='0')now=f[now];
        if(b[now+1]=='0')now++;
        go[i][0]=now;
        now=i;
        while(now!=-1&&b[now+1]!='1')now=f[now];
        if(b[now+1]=='1')now++;
        go[i][1]=now;
    }


    dp[1][0][0]=0;
    //for(int i= 1;i<=n;i++)dp[1][i][0]=1e9;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<=n;j++){
            for(int k=0;k<m;k++){
                dp[i&1][j][k]=1e9;
            }
        }
        for(int j =0;j<=n;j++){
            for(int k = 0;k<m;k++){
                if(a[i]=='0'){
                    int tarj,tark;
                    if(k==0){
                        tarj=j;
                        if(b[0]=='0')tark=0;
                        else tark=-1;
                    }
                    else{
                        tarj=j;
                        tark=go[k-1][0];
                    }
                    if(b[tark+1]==0)tarj++,tark=f[tark];
                    tark++;
                    dp[i&1][tarj][tark]=min( dp[i&1][tarj][tark],dp[(i&1)^1][j][k]);
                    if(k==0){
                        tarj=j;
                        if(b[0]=='1')tark=0;
                        else tark=-1;
                    }
                    else{
                        tarj=j;
                        tark=go[k-1][1];
                    }
                    if(b[tark+1]==0)tarj++,tark=f[tark];
                  //  if(b[tark+1]==0)tarj++,tark=f[tark];
                    tark++;

                    dp[i&1][tarj][tark]=min( dp[i&1][tarj][tark],dp[(i&1)^1][j][k]+1);
                }
                else{
                     int tarj,tark;
                    if(k==0){
                        tarj=j;
                        if(b[0]=='0')tark=0;
                        else tark=-1;
                    }
                    else{
                        tarj=j;
                        tark=go[k-1][0];
                    }
                    if(b[tark+1]==0)tarj++,tark=f[tark];
                    tark++;
                    dp[i&1][tarj][tark]=min( dp[i&1][tarj][tark],dp[(i&1)^1][j][k]+1);
                    if(k==0){
                        tarj=j;
                        if(b[0]=='1')tark=0;
                        else tark=-1;
                    }
                    else{
                        tarj=j;
                        tark=go[k-1][1];
                    }
                    if(b[tark+1]==0)tarj++,tark=f[tark];
                  //  if(b[tark+1]==0)tarj++,tark=f[tark];
                    tark++;
                    dp[i&1][tarj][tark]=min( dp[i&1][tarj][tark],dp[(i&1)^1][j][k]);
                }
            }
        }
        for(int j = 0;j<=n;j++){
            for(int k =0;k<=m;k++){
            //    printf("%d ",dp[i&1][j][k]);
            }
          //  printf("\n");
        }
    }
    for(int i = 0;i<=n-m+1;i++){
        int x=(n-1)&1,y=i;
        int res=1e9;
        for(int j = 0;j<m;j++)res=min(res,dp[x][y][j]);
        if(res==1e9)printf("-1 ");
        else
        printf("%d ",res);
    }
    printf("\n");
}
int main(){
    int t=1;//00;//00;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
*/