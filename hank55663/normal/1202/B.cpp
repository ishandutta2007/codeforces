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
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 1500005
//#define next Next
#define index Index
#define rank Rank
#define context Context
int main(){
    char c[2000005];
    int cnt[15][15];
    MEM(cnt);
    scanf("%s",c);
    int last=0;
    for(int i = 1;c[i]!=0;i++){
        cnt[last][c[i]-'0']++;
        last=c[i]-'0';
    }
    for(int x = 0;x<10;x++){
        for(int y = 0;y<10;y++){
            LL dis[10][10];
            for(int i=0;i<10;i++){
                for(int j =0;j<10;j++){
                    dis[i][j]=1e9;
                }
                //dis[i][i]=0;
                dis[i][(i+x)%10]=1;
                dis[i][(i+y)%10]=1;
            }
            for(int i = 0;i<10;i++){
                for(int j =0;j<10;j++){
                    for(int k =0;k<10;k++){
                        dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
                    }
                }
            }
            LL sum=0;
            for(int i =0;i<10;i++){
                for(int j =0;j<10;j++){
                    sum+=(dis[i][j]-1)*cnt[i][j];
                }
            }
            if(sum>1e8){
                sum=-1;
            }
            printf("%lld ",sum);
        }
        printf("\n");
    }
    return 0;
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */