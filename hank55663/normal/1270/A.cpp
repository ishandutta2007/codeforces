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
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k1,k2;
        scanf("%d %d %d",&n,&k1,&k2);
        int win=0;
        for(int i = 0;i<k1;i++){
            int x;
            scanf("%d",&x);
            if(x==n)win=1;
        }
        for(int i= 0;i<k2;i++){
            int x;
            scanf("%d",&x);
        }
        if(win)printf("YES\n");
        else printf("NO\n");
    }
}
/*
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