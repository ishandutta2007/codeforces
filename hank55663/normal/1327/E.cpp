#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long
#define ULL unsigned long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define pi acos(-1)
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int mod=998244353;
LL f_pow(LL a,LL b){
    if(b<0)return 0;
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
    for(int i = 1;i<=n;i++){
        LL sum=0;
        if(i==n)sum=10;
        else{
            sum=f_pow(10,n-i-1)*10%mod*9%mod*2%mod+f_pow(10,n-i-2)*10%mod*81%mod*(n-i-1)%mod;
        }
        /*
        for(int j=1;j<=n-i+1;j++){
            if(j==1&&j==n-i+1){
                sum=10;
            }
            else if(j==1||j==n-i+1){
                sum+=f_pow(10,n-i-1)*10%mod*9%mod;
                sum%=mod;
            }
            else{
                sum+=f_pow(10,n-i-2)*10%mod*81%mod;
                sum%=mod;
            }
        }*/
        printf("%lld ",sum%mod);
    }
    printf("\n");
}
/*

5
AACCMMAA
A
AA
MM
ACA
ACMAA


5
0 9 7 1 100
-1 0 -1 -1 91
-1 5 0 -1 96
-1 8 9 0 99
-1 -1 -1 -1 0
3 4
3 5
5 6
5 7
3 or 4
3 or 5
5 or 6
5 or 7

dp[x]=max(dp[x-w_i*j]+j*t_i-delta t_i*j*(j-1)/2)
dp[x]=max(dp[j]+x*t_i-j*t_i-delta t_i*(x-j)*(x-j-1)/2)
dp[x]=max(dp[j]-j*t_i-delta t_i *(j^2/2+j/2) - 
        delta t_i * xj + x*t_i + delta t_i * (x^2/2-x/2))
dp[x]=max(dp[j] + g(j) - delta t_i *xj + w(i) )
g(j)= dp[j]-j*t_i-delta t_i *(j^2/2+j/2)
w(i)=  x*t_i + delta t_i * (x^2/2-x/2)
x^2/2 -xj -x/2  +j^2/2 +j/2
*/

/*
 

*/