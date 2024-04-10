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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 205
LL fra[500005];
int mod=998244353;
LL f_pow(LL a,LL b){
    
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL inv(LL a){
    return f_pow(fra[a],mod-2);
}
LL C(int a,int b){
    if(b<0)return 0;
    if(a<b)return 0;
    return fra[a]*inv(b)%mod*inv(a-b)%mod*f_pow(2,b)%mod;
}
int main(){
    fra[0]=1;
    for(int i = 1;i<500005;i++){
        fra[i]=fra[i-1]*i%mod;
    }
    int n,m;
    scanf("%d %d",&n,&m);
    LL ans=0;
    for(int i = 2;i<=m;i++){
        ans+=C(i-2,n-3)*(i-1)%mod;
        //printf("%d %d\n",(i-1)*2,n-1);
        ans%=mod;
    }
    printf("%lld\n",ans);
}
/*
[1,2,4,3,5,6]
concat(sorted([4,2,1]),sorted([5,3,6]))
concat(shuffle([2,1]),shuffle([2,3]))
concat(shuffle([2,1,3]),shuffle([3]))
*/