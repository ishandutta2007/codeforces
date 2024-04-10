#include <cstdio>
using namespace std;
int n;
int arr[200005];
const int MOD=998244353;

long long qexp(int b,int pow){
    if (pow==0) return 1;
    if (pow==1) return b;
    
    long long h=qexp(b,pow>>1);
    h=(h*h)%MOD;
    if (pow&1) h=(h*b)%MOD;
    return h;
}

int main(){
    scanf("%d",&n);
    for (int x=0;x<n;x++){
        scanf("%d",&arr[x]);
    }
    
    long long inv=qexp(100,MOD-2);
    
    for (int x=0;x<n;x++) arr[x]=(arr[x]*inv)%MOD;
    
    long long checkpoint=0;
    long long curr=0;
    for (int x=n-1;x>=0;x--){
        curr=(curr*arr[x])%MOD;
        checkpoint=(checkpoint*arr[x])%MOD;
    
        curr=(curr+1)%MOD;
        checkpoint=(checkpoint+1-arr[x]+MOD)%MOD;
        //printf("%d %d\n",curr,checkpoint);
    }
    
    int numer=(1-checkpoint+MOD)%MOD;
    
    printf("%d\n",(qexp(numer,MOD-2)*curr)%MOD);
}