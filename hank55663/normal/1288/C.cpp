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
LL fra[100005];
int mod=1e9+7;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL C(LL a,LL b){
   // printf("%d %d\n",a,b);
    return fra[a]*f_pow(fra[b],mod-2)%mod*f_pow(fra[a-b],mod-2)%mod;
}
int main(){
    fra[0]=1;
    for(int i = 1;i<10005;i++)
        fra[i]=fra[i-1]*i%mod;;
    int n,m;
    scanf("%d %d",&n,&m);
    printf("%lld\n",C(2*m+n-1,n-1));
}
//a+a+1=10a+1
//3a+2=10a+2