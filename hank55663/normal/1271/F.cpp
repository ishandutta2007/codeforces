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
#define MXN 200005
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a[2][3];
        for(int i=0;i<2;i++)
            for(int j=0;j<3;j++)
                scanf("%d",&a[i][j]);
        int d[8];
        for(int i =1;i<=7;i++)
            scanf("%d",&d[i]);
        for(int i=0;i<=d[2];i++){
            for(int j=0;j<=d[3];j++){
                for(int k=0;k<=d[5];k++){
                    int x=a[0][0]-i-j,y=a[0][1]-i-k,z=a[0][2]-j-k;
                    if(x<0||y<0||z<0)break;
                    int Min=min(min(x,min(z,y)),d[1]);
                    x-=Min,y-=Min,z-=Min;
                    x=min(x,d[4]);
                    y=min(y,d[6]);
                    z=min(z,d[7]);
                    int f[8];
                    f[1]=d[1]-Min;
                    f[2]=d[2]-i;
                    f[3]=d[3]-j;
                    f[4]=d[4]-x;
                    f[5]=d[5]-k;
                    f[6]=d[6]-y;
                    f[7]=d[7]-z;
                    if(f[1]+f[2]+f[3]+f[4]<=a[1][0]&&f[1]+f[2]+f[5]+f[6]<=a[1][1]&&f[1]+f[3]+f[5]+f[7]<=a[1][2]){
                        printf("%d %d %d %d %d %d %d\n",Min,i,j,x,k,y,z);
                        goto end;                       
                    }
                }
            }
        }
        printf("-1\n");
        end:
            continue;
    }
}