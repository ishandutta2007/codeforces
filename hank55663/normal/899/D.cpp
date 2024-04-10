#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define next Next
int main(){
    LL n;
    scanf("%lld",&n);
    LL Max=0;
    LL now=1;
    LL x=n+n-1;
    int Now= 100;
    int aans=0;
    /*while(Now<=1000){
        for(int i = 1;i<=n;i++){
            int xx=Now-i-1;
            if(xx>=i&&xx<=n)
            aans++;
        }
        printf("%d\n",aans);
        Now+=100;
    }*/
   // printf("%d\n",aans);
    while(x>=now-1){
        Max++;
        now*=10;
    }
    if(n<=4){
        printf("%lld\n",n*(n-1)/2);
        return 0;
    }
    /*if(now/10-1>n){
        printf("%lld\n",n-(now/10-1)/2);
    }
    else{*/
        LL ans=0;
        now/=10;
    //printf("%lld\n",now);
        LL temp=now;
        while(true){
            if(now-1<=n){
                ans+=(now-1)/2;
            }
            else{
                ans+=max(n-(now-1)/2,0ll);
          //      break;
            }
            now+=temp;
            if(now-1>n+n-1)
            break;
         //   printf("%d %d\n",ans,now);
           // ans+=now-(now-1)/2
        }
        printf("%lld\n",ans);
  //  }

}
/*
1 8 18
2 7 17
3 6 16
4 5 15
5 14
6 13
7 12
8 11
9 10
10 19
11 18
12 17
13 16
14 15
0 ~ 2345 2
2346 ~ 9999 1
 9999
12345
*/