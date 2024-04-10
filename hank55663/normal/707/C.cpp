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
#define MXN 200005
const int mod=1e9+7;
int main(){ 
    LL n;
    scanf("%lld",&n);
    if(n<=2){
        printf("-1");
    }
    else{
        LL pro=1;
        while(n%2==0){
            if(n==4){
                printf("%lld %lld\n",3*pro,5*pro);
                return 0;
            }
            else{
                pro*=2;
                n/=2;
            }
        }
        printf("%lld %lld\n",n*n/2*pro,(n*n/2+1)*pro);
    }
}
/*
1 2 2 3 3 3 4
2 2 1
3 2 3
4 2 4 4 7
 
1 1
*/