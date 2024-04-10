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
#define MAXN 205
#define N 262144
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
LL fra[2000005];
LL inv[2000005];
LL C(int a,int b){
    return fra[a]*inv[b]%mod*inv[a-b]%mod;
}
LL pre[2000005];
int main(){
    fra[0]=1;
    for(int i = 1;i<2000005;i++)fra[i]=fra[i-1]*i%mod;
    inv[2000004]=f_pow(fra[2000004],mod-2);
    for(int i = 2000003;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    LL n,m;
    pre[0]=1;
    scanf("%lld %lld",&n,&m);
    for(int i = 1;i<=n;i++){
        pre[i]=(pre[i-1]+C(n-i,i))%mod;
    }
    LL ans=f_pow(m,n);
    for(int i = 0;i<n;i++){
        ans+=f_pow(m,i+1)*f_pow(2*m-1,n-i-1)%mod;//f_pow(m,i)*f_pow(m-1,n-i)%mod*pre[i-1]%mod;//C(n,i)%mod*(((LL)i*(i+1)/2)%mod)%mod;
    }
    /*
    for(int i = 1;i<=n;i++){
        for(int j=0;j<=n-i;j++)
            ans+=C(i+j-1,j)*f_pow(m-1,j)%mod*f_pow(m,n-j)%mod;//f_pow(m,i)*f_pow(m+(m-1)*i,n-i);
        //printf("%lld\n",ans);
        ans%=mod;
    }*/
    printf("%lld\n",ans%mod);
}
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/