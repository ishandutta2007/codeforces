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
#define MXN 1005
#define N 10000
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,x,y;
        scanf("%d %d %d",&n,&x,&y);
        if(x==1&&y==1){
            printf("1 1\n");
        }
        else
        printf("%d %d\n",min(max(x+y-n+1,1),n),min(x+y-1,n));
    }
    return 0;
}