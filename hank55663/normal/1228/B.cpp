




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
#define MXN 2000005
LL mod=1e9+7;
LL f_pow(LL a,LL b){
    LL temp=a,res=1;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int grid[1005][1005];
int main(){
    int h,w;
    scanf("%d %d",&h,&w);
    MEMS(grid);
    for(int i = 0;i<h;i++){
        int x;
        scanf("%d",&x);
        for(int j = 0;j<x;j++){
            grid[i][j]=1;
        }
        grid[i][x]=0;
    }
    for(int i = 0;i<w;i++){
        int x;
        scanf("%d",&x);
        for(int j=0;j<x;j++){
            if(grid[j][i]==0){
                printf("0\n");
                return 0;
            }
            grid[j][i]=1;
        }
        if(grid[x][i]==1){
            printf("0\n");
            return 0;
        }
        grid[x][i]=0;
    }
    int tot=0;
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){
            if(grid[i][j]==-1)tot++;
        }
    printf("%lld\n",f_pow(2,tot));
    return 0;
}