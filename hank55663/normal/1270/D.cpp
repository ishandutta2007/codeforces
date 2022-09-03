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
#define N 100005
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    n=k+1;
    map<int,int> s;
    for(int i = 1;i<=n;i++){
        printf("?");
        for(int j = 0;j<k;j++){
            printf(" %d",(i+j-1)%n+1);
        }
        printf("\n");
        fflush(stdout);
        int x,px;
        scanf("%d %d",&x,&px);
        s[px]++;;
    }
    printf("! %d\n",s.rbegin()->y);
   // printf("\n");
}
/*
1 2 3 4 5
1 2 3 4 5 6
1 2 3 4 5    3
1 2 3 5 6    4 
1 2 3 4 6
3
0 1 2
0 2 2.5

1 2 3 4 5
1 2 3 4 5
1 3
1 4
1
*/
/*
AC
AGCG
AGCGU
AT
*/