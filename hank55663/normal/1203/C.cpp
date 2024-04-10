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
#define MXN 1500005
//#define next Next
#define index Index
#define rank Rank
#define context Context
int main(){
    //int q;
   // scanf("%d",&q);
   // while(q--){
        LL gcd=0;
        int n;
        scanf("%d",&n);
        for(int i = 0;i<n;i++){
            LL x;
            scanf("%lld",&x);
            gcd=__gcd(x,gcd);
        }
        int cnt=0;
        for(LL i = 1;i*i<=gcd;i++){
            if(gcd%i==0){
                cnt++;
                if(gcd/i!=i){
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
   // }
    return 0;
}
/*
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */