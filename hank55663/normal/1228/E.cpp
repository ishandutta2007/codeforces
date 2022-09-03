




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
#define N 100005
#define MXN 2000005
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
LL C[255][255];
void build(){
    for(int i = 0;i<255;i++){
        C[i][0]=C[i][i]=1;
        for(int j =1;j<i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    LL res=0;
    build();
    for(int i =0;i<=2*n;i++){
        for(int j =0;j<=i&&j<=n;j++){
            int a=j,b=i-j;
            if(a<=n&&b<=n){
                LL pro=C[n][a]*C[n][b]%mod;
                LL num=a*n+b*n-a*b;
                LL Less=n*n-num;
                if(i&1){
                    res-=pro*f_pow(k-1,num)%mod*f_pow(k,Less)%mod;
                }
                else{
                    res+=pro*f_pow(k-1,num)%mod*f_pow(k,Less)%mod;
                }
                res=(res%mod+mod)%mod;
            }
        }
    }
    printf("%lld\n",res);
    return 0;
}