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
#define MXN 30005
#define next Next
#define index Index
int main(){
    int n;
    scanf("%d",&n);
    int ans[5005];
    printf("? 1 2\n");
    fflush(stdout);
    int x;
    scanf("%d",&x);
    printf("? 2 3\n");
    fflush(stdout);
    int y;
    scanf("%d",&y);
    printf("? 1 3\n");
    fflush(stdout);
    int z;
    scanf("%d",&z);
    ans[1]=(x+z-y)/2;
    ans[2]=x-ans[1];
    ans[3]=z-ans[1];
    for(int i =4;i<=n;i++){
        printf("? 1 %d\n",i);
        fflush(stdout);
        int xx;
        scanf("%d",&xx);
        ans[i]=xx-ans[1];
    }
    printf("!");
    for(int i = 1;i<=n;i++)
        printf(" %d",ans[i]);
    printf("\n");
    fflush(stdout);
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */