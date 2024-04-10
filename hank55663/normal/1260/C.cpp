#include<bits/stdc++.h>
#pragma optimizer(O2)
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
//#define MXN 300000
#define N 100005

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL r,b,k;
        scanf("%lld %lld %lld",&r,&b,&k);
        LL lcm=r*b/__gcd(r,b);
        LL gcd=__gcd(r,b);
        r/=gcd;
        b/=gcd;
        /*if(k==2){
            if(r!=b)
            printf("REBEL\n");
            else
            printf("OBEY\n");
            continue;
        }*/
        if(r>b)swap(r,b);
        if((b-1-1)/r+1>=k){
            printf("REBEL\n");
        }
        else{
            printf("OBEY\n");
        }

    }
}