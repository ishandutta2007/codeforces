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
#define MXN 205
int a[1005][1005];
int len[1005][1005][8];
float val[1005][1005][8][10];
double ans[1005][1005][2];
int n;
int X[8]={-1,-1,1,1,-1,0,0,1};
int Y[8]={-1,1,-1,1,0,-1,1,0};
int DP(int x,int y,int dir){
    if(x<1||x>n||y<1||y>n)return 0;
    if(len[x][y][dir]!=-1)return len[x][y][dir];
    if(a[x][y]==0)return len[x][y][dir]=0;
    return len[x][y][dir]=DP(x+X[dir],y+Y[dir],dir)+1;
}
int main(){
    //int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            scanf(" %c",&c);
            a[i][j]=c-'0';
            for(int k=0;k<8;k++){
                if(a[i][j]==0)
                val[i][j][k][0]=-1e9;
                else
                val[i][j][k][0]=log(a[i][j]);
            }
        }
    }
    MEMS(len);
    for(int t = 1;t<10;t++){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                for(int k=0;k<8;k++){
                    int x=i+X[k]*(1<<(t-1)),y=j+Y[k]*(1<<(t-1));
                    if(x<1||x>n||y<1||y>n){
                        val[i][j][k][t]=-1e9;
                    }
                    else{
                        val[i][j][k][t]=val[i][j][k][t-1]+val[x][y][k][t-1];
                    }
                }
            }
        }
    }
    double res=-1;
    int x=0,y=0,t;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            int dis=min(min(DP(i,j,0),DP(i,j,1)),min(DP(i,j,2),DP(i,j,3)));
            if(a[i][j]==0){
                ans[i][j][0]=ans[i][j][1]=-1e9;
            }
            else{
                ans[i][j][0]=0;
                for(int k=0;k<4;k++){
                    int x=i,y=j;
                    for(int d=0;d<10;d++){
                        if(dis&(1<<d)){
                            ans[i][j][0]+=val[x][y][k][d];
                            x+=X[k]*(1<<d);
                            y+=Y[k]*(1<<d);
                        }
                    }
                }
                ans[i][j][0]-=log(a[i][j])*3;
                if(ans[i][j][0]>res){
                    res=ans[i][j][0];
                    x=i,y=j,t=0;
                }
                dis=min(min(DP(i,j,4),DP(i,j,5)),min(DP(i,j,6),DP(i,j,7)));
               /* if(i==4&&j==3){
                    printf("%d %lf %lf %lf %lf\n",dis,val[i][j][4][1],val[i][j][5][1],val[i][j][6][1],val[i][j][7][1]);
                }*/
                ans[i][j][1]=0;
                for(int k=4;k<8;k++){
                    int x=i,y=j;
                    for(int d=0;d<10;d++){
                        if(dis&(1<<d)){
                            ans[i][j][1]+=val[x][y][k][d];
                            x+=X[k]*(1<<d);
                            y+=Y[k]*(1<<d);
                        }
                    }
                }
                ans[i][j][1]-=log(a[i][j])*3;
                if(ans[i][j][1]>res){
                    res=ans[i][j][1];
                    x=i,y=j,t=1;
                }
            }
        }
    }
    if(res<0){
        printf("0\n");
        return 0;
    }
  //  printf("%lf %lf\n",exp(ans[3][3][1]),exp(ans[x][y][t]));
  //  printf("%d %d %d\n",x,y,t);
    if(t==0){
        int dis=min(min(DP(x,y,0),DP(x,y,1)),min(DP(x,y,2),DP(x,y,3)));
        LL ans=1;
        int mod=1e9+7;
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(abs(x-i)==abs(y-j)&&abs(x-i)<dis){
                    ans*=a[i][j];
                    ans%=mod;
                }
            }
        }
        printf("%lld\n",ans);
    }
    else{
        int dis=min(min(DP(x,y,4),DP(x,y,5)),min(DP(x,y,6),DP(x,y,7)));
        LL ans=1;
        int mod=1e9+7;
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if((x==i||y==j)&&abs(x-i)<dis&&abs(y-j)<dis){
                    ans*=a[i][j];
                    ans%=mod;
                }
            }
        }
        printf("%lld\n",ans);
    }
}
/*
4+3+3+4+3+2+2+1
*/