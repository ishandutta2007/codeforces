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
    int x[3];
    for(int i = 0;i<3;i++){
        scanf("%d",&x[i]);
    }
    sort(x,x+3);
    printf("%d\n",x[2]-x[0]);

}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */