#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=1e9+7;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL fra[200005];
LL inv[200005];
LL C(int a,int b){
    return fra[a]*inv[b]%mod*inv[a-b]%mod;
}
void solve(int T){
    int n,k;
    scanf("%d %d",&n,&k);
    if(k>=n){
        printf("%lld\n",f_pow(2,n));
    }
    else{
        fra[0]=1;
        for(int i = 1;i<=n;i++)fra[i]=fra[i-1]*i%mod;
        inv[n]=f_pow(fra[n],mod-2);
        for(int i = n;i>=1;i--)inv[i-1]=inv[i]*i%mod;
        LL res=0;
        for(int i = 0;i<=k;i++)res+=C(n,i);
        printf("%lld\n",res%mod);
    }
  
}
int main(){
    int t=1;
   // scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*
*/