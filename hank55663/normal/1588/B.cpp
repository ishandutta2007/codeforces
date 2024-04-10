#include<bits/stdc++.h>
#pragma optimize(Ofast)
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<LL,LL>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    printf("? 1 %d\n",n);
    fflush(stdout);
    LL tot;
    scanf("%lld",&tot);
    int Max=n,Min=0;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        printf("? 1 %d\n",mid);
        fflush(stdout);
        LL x;
        scanf("%lld",&x);
        if(x==tot)Max=mid;
        else Min=mid;
    }
    printf("? 1 %d\n",Max-1);
    fflush(stdout);
    LL x;
    scanf("%lld",&x);
    LL k=Max;
    LL j = k-(tot-x);
    tot-=(k-j+1)*(k-j)/2;
    printf("? 1 %lld\n",j-2);
    fflush(stdout);
    scanf("%lld",&x);
    LL i = j-1-(tot-x);
    printf("! %lld %lld %lld\n",i,j,k);
    fflush(stdout);
}

int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/