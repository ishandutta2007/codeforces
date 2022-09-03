#include<bits/stdc++.h>
using namespace std;
#pragma optimizer(-Ofast)
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
#define rank Rank
#define MXN 15000
//#define MXN 300005
int main(){
    ///int a[150005];
    int t;
    scanf("%d",&t);
    while(t--){
       LL n,m;
       scanf("%lld %lld",&n,&m);
       LL ans=0;
       for(int i=1;i<=9;i++){
           ans+=(n-m*i+m*10)/(m*10)*(m*i%10);
       } 
       printf("%lld\n",ans);
    }
    return 0;
}