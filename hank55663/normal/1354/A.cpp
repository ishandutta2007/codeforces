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
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&d,&c);
        a-=b;
        if(a<=0){
            printf("%d\n",b);
        }
        else if(c>=d){
            printf("-1\n");
        }
        else{
            LL tot=(a+d-c-1)/(d-c);
            printf("%lld\n",b+d*tot);
        }
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