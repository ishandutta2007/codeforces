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
int main(){
    LL n,m,q;
    scanf("%lld %lld %lld",&n,&m,&q);
    LL gcd=__gcd(n,m);
    LL nn=n/gcd,mm=m/gcd;
    while(q--){
        LL sx,sy,ex,ey;
        scanf("%lld %lld %lld %lld",&sx,&sy,&ex,&ey);
        LL blockx,blocky;
        if(sx==1){
            blockx=(sy-1)/nn;
        }
        else{
            blockx=(sy-1)/mm;
        }
        if(ex==1){
            blocky=(ey-1)/nn;
        }
        else{
            blocky=(ey-1)/mm;
        }
        if(blockx==blocky){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}