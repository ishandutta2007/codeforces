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
//#define N 262144
#define ULL unsigned long long
#define ll long long
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
int main(){
    int n;
    scanf("%d",&n);
    LL c[300005];
    for(int i = 1;i<=n;i++)scanf("%lld",&c[i]);
    sort(c+1,c+n+1);
    c[0]=0;
    for(int i = 1;i<=n;i++)c[i]+=c[i-1],c[i]%=mod;
    for(int i = 1;i<=n;i++){
        int need=n-i,block=i;
        LL ans=0;
        while(need>=0){
            ans+=c[need];
            need-=block;
            ans%=mod;
        }   
        printf("%lld ",ans*f_pow(n,mod-2)%mod);
    }
    printf("\n");
}