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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
//#define MXN 300000
#define N 100005
LL dis[30000005];
int main(){
    LL n,xx,y;
    scanf("%lld %lld %lld",&n,&xx,&y);
    fill(dis,dis+30000005,1e18);
    dis[0]=0;
    for(int i =1;i<=2*n;i++){
       // if(i%10000==0){
           
       // }
        if(i&1){
            dis[i]=min(dis[i],dis[i-1]+xx);
        }
        else{
            dis[i]=min(dis[i],min(dis[i-1]+xx,dis[i/2]+y));
        }
        if(dis[i-1]>dis[i]+xx){
            dis[i-1]=dis[i]+xx;
            i-=2;
        }
    }
    assert(dis[n]!=1e18);
    assert(dis[n]>=0);
    printf("%lld\n",dis[n]);
}