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
int ans[1005][1005];
int main(){
    int a[4][4]={{0,1,2,3},{5,4,7,6},{8,9,15,14},{13,12,10,11}};
    int n;
    scanf("%d",&n);
    int now=0;
    for(int i = 0;i<n/4;i++){
        for(int j = 0;j<n/4;j++){
            for(int x=0;x<4;x++)
                for(int y=0;y<4;y++){
                    ans[i*4+x][j*4+y]=a[x][y]+now;
                }
            now+=16;
        }
    }
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}