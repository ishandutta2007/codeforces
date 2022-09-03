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
#define MXN 300000
int main(){
    LL n,p,w,d;
    scanf("%lld %lld %lld %lld",&n,&p,&w,&d);
    LL xx=0,yy=0;
    LL lcm=w*d/__gcd(w,d);
    xx=p/lcm*(lcm/w);
   // else yy=p/lcm*(lcm/d);
    p%=lcm;
    for(int i = 0;i<=100000;i++){
        LL x=i,y=p-i*w;
        if(y%d==0){
            y=y/d;
            if(x+xx+y+yy<=n&&x+xx>=0&&y+yy>=0){
                printf("%lld %lld %lld\n",x+xx,y+yy,n-x-xx-y-yy);
                return 0;
            }
        }
        y=i,x=p-i*d;
        if(x%w==0){
            x=x/w;
            if(x+xx+y+yy<=n&&x+xx>=0&&y+yy>=0){
                printf("%lld %lld %lld\n",x+xx,y+yy,n-x-xx-y-yy);
                return 0;
            }
        }
    }
    printf("-1\n");
}
/*
3 5 12
..X..
R..?.
LX...
100 100 100 100 8
1000000000000
100000000000000000
100000
1
*/