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
#define N 2000005
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        pii a[1005],b[1005];
        for(int i = 0;i<n;i++){
            scanf("%d",&a[i].x);
            a[i].y=i;
        }
        for(int i = 0;i<n;i++){
            scanf("%d",&b[i].x);
            b[i].y=i;
        }
        sort(a,a+n);
        sort(b,b+n);
        for(int i  =0;i<n;i++){
            printf("%d ",a[i].x);
        }
        printf("\n");
        for(int i = 0;i<n;i++){
            printf("%d ",b[i].x);
        }
        printf("\n");
    }
}