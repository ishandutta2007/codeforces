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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 300000
#define N 100005
int a[8][8]={
    1,0,0,0,0,0,0,0,
    3,0,0,0,0,0,0,0,
    4,0,0,0,0,0,0,0,
    5,0,0,0,0,0,0,0,
    6,0,0,0,0,0,0,0,
    7,0,0,0,0,0,0,0,
    8,0,0,0,0,0,0,0,
    2,14,9,10,11,12,13,1
};
int b[8][8]={
    1,19,20,21,22,23,24,2,
    4,30,29,28,27,26,25,3,
    5,31,32,33,34,35,36,6,
    8,42,41,40,39,38,37,7,
    9,18,43,44,45,46,47,10,
    12,53,52,51,50,49,48,11,
    54,16,63,62,61,60,15,17,
    13,55,56,57,58,59,14,1
};
int main(){
    int n;
    scanf("%d",&n);
    if(n<=14){
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++){
                if(a[i][j]<=n&&a[i][j]!=0){
                    printf("%c%d ",i+'a',j+1);
                }
            }
        //printf("\n");
    }
    else if(n>=17){
        for(int i=0;i<6;i++){
            if(i&1)
            for(int j=7;j>=0;j--){
                if(b[i][j]<=n&&b[i][j]!=0){
                    printf("%c%d ",i+'a',j+1);
                }
            }
            else
            for(int j=0;j<8;j++){
                if(b[i][j]<=n&&b[i][j]!=0){
                    printf("%c%d ",i+'a',j+1);
                }
            }
        }
        if(b[6][0]<=n){
            printf("%c%d ",6+'a',0+1);
        }
        for(int j=0;j<7;j++){
            if(b[7][j]<=n&&b[7][j]!=0){
                    printf("%c%d ",7+'a',j+1);
                }
        }
        if(b[6][6]<=n){
            printf("%c%d ",6+'a',6+1);
        }
        for(int j=1;j<6;j++){
             if(b[6][j]<=n&&b[6][j]!=0){
                    printf("%c%d ",6+'a',j+1);
                }
        }
        if(b[6][7]<=n){
            printf("%c%d ",6+'a',7+1);
        }
        if(b[7][7]){
printf("%c%d ",7+'a',7+1);  
        }
    }
    else if(n==15){
        printf("a1 c1 b1");
        for(int j=2;j<=8;j++)
        printf(" b%d",j);
        for(int j=2;j<8;j++)
        printf(" %c8",'a'+j);
    }
    else if(n==16){
         printf("a1 c1 d1 b1");
        for(int j=2;j<=8;j++)
        printf(" b%d",j);
        for(int j=2;j<8;j++)
        printf(" %c8",'a'+j);
    }
    printf("\n");
}