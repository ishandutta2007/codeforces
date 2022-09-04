#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    printf("YES\n");
    if(k%2==0){
        for(int i=0;i<4;i++){
            for(int j=0;j<n;j++){
                if(i==0||i==3)
                printf(".");
                else if(j!=0&&j<=k/2)
                printf("#");
                else
                printf(".");
            }
            printf("\n");
        }
    }
    else if(k==1){
        for(int i=0;i<4;i++){
            for(int j=0;j<n;j++){
                if(i==1&&j==n/2)
                printf("#");
                else
                printf(".");
            }
            printf("\n");
        }
    }
    else if(k==3){
        for(int i=0;i<4;i++){
            for(int j=0;j<n;j++){
                if(i==1&&j==n/2)
                printf("#");
                else if(i==2&&(j==n/2+1||j==n/2-1))
                printf("#");
                else
                printf(".");
            }
            printf("\n");
        }
    }
    else{
        k++;
        for(int i=0;i<4;i++){
            for(int j=0;j<n;j++){
                if(i==0||i==3)
                printf(".");
                else if(j!=0&&j<=k/2&&(i!=1||j!=2))
                printf("#");
                else
                printf(".");
            }
            printf("\n");
        }
    }
}
/*
6 4 8 2
4 8 2 2
6 8 2 2
6 4 2 2
6 2 2
6 4 2
8 2 2

*/