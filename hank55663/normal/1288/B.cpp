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
int main(){
   /* for(LL i = 1;i<=1000000000;i++){
        LL num=10;
        while(num<=i)num*=10;
       // (i+1)*a+i=num*a+i
    }*/
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        LL ans=0;
        scanf("%d %d",&a,&b);
        for(LL i=10;i-1<=b;i*=10){
            ans+=a;
        }
        printf("%lld\n",ans);
    }
}
//a+a+1=10a+1
//3a+2=10a+2