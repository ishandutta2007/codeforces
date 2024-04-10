#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    LL n,k;
    scanf("%lld %lld",&n,&k);
    LL ans=0;
    LL now=1;
    while(now<=k&&now<n){
        now=now*2;
        ans++;
    }
    if(now<n){
        ans+=(n-now+k-1)/k;
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;//00;//00;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
*/