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
#define MAXN 205
#define N 262144
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        double angle=pi/n;
        double edge=sqrt(1/(2-2*cos(angle)));
       // printf("%lf %lf %lf\n",edge,angle,cos(angle));
        printf("%.12lf\n",sqrt(edge*edge+edge*edge-2*cos(angle*(n-1))*edge*edge));
        //a*a+a*a-2*cos*a*a=1
    }
}

/*
C[i][j]=C[i>>1][j]
1000

1001
0000
0001
1000
1001
*/