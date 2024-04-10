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
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 100005
int ans[505][505][505];
int cnt[4][505][505];
char c[505][505];
int main(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf(" %c",&c[i][j]);
            if(c[i][j]=='R')cnt[0][i][j]++;
            if(c[i][j]=='G')cnt[1][i][j]++;
            if(c[i][j]=='Y')cnt[2][i][j]++;
            if(c[i][j]=='B')cnt[3][i][j]++;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<4;k++){
                cnt[k][i][j]+=cnt[k][i-1][j]+cnt[k][i][j-1]-cnt[k][i-1][j-1];
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=min(i-1,j-1);k++){
                int ok=0;
                if(cnt[0][i-1][j-1]-cnt[0][i-k-1][j-1]-cnt[0][i-1][j-k-1]+cnt[0][i-k-1][j-k-1]==k*k){
                    ok++;
                }
                if(cnt[1][i-1][j+k-1]-cnt[1][i-k-1][j+k-1]-cnt[1][i-1][j-1]+cnt[1][i-k-1][j-1]==k*k){
                    ok++;
                }
                if(cnt[2][i+k-1][j-1]-cnt[2][i-1][j-1]-cnt[2][i+k-1][j-k-1]+cnt[2][i-1][j-k-1]==k*k){
                    ok++;
                }
                if(cnt[3][i+k-1][j+k-1]-cnt[3][i-1][j+k-1]-cnt[3][i+k-1][j-1]+cnt[3][i-1][j-1]==k*k){
                    ok++;
                }
               // printf("%d %d %d %d\n",i,j,k,ok);
                if(ok==4){
                    ans[k][i][j]++;
                }
                else{
                    break;
                }

            }
        }
    }
   // printf("?\n");
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=500;k++){
                ans[k][i][j]+=ans[k][i-1][j]+ans[k][i][j-1]-ans[k][i-1][j-1];
            }
        }
    }
    //printf("!\n");
    while(q--){
        int r1,c1,r2,c2;
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
        int Max=min(r2-r1+1,c2-c1+1)/2+1,Min=0;
        while(Max>Min+1){
            int mid=(Max+Min)/2;
            int rr1=r1+mid,cc1=c1+mid,rr2=r2-mid+1,cc2=c2-mid+1;
            if(ans[mid][rr2][cc2]-ans[mid][rr1-1][cc2]-ans[mid][rr2][cc1-1]+ans[mid][rr1-1][cc1-1]){
                Min=mid;
            }
            else{
                Max=mid;
            }
        }
        printf("%d\n",Min*Min*4);
    }
}