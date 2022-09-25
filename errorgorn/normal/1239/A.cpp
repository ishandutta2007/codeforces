#include <cstdio>
#include <cstring>
using namespace std;

int a,b;
int memo[100005];
const int MOD=1000000007;
long long fibo(int i){
    if (i<=1) return 1;
    else if (memo[i]!=-1) return memo[i];
    else return memo[i]=(fibo(i-1)+fibo(i-2))%MOD;
}
int main(){
    memset(memo,-1,sizeof(memo));
    scanf("%d%d",&a,&b);
    
    printf("%lld\n",2*(fibo(a)+fibo(b)-1)%MOD);
}