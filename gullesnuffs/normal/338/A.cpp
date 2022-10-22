#include <stdio.h>
#define MOD 1000000009LL

using namespace std;

long long powerMod(long long p){
    long long x[32];
    x[0]=2;
    for(int i=0; i < 31; ++i)
        x[i+1]=(x[i]*x[i])%MOD;
    long res=1;
    for(int i=0; i < 31; ++i){
        if(p & (1LL<<i))
            res=(res*x[i])%MOD;
    }
    return res;
}

int main()
{
    long long questionN, correctN, cons, wrongN;
    scanf("%I64d%I64d%I64d", &questionN, &correctN, &cons);
    wrongN=questionN-correctN;
    long long Min=-1, Max=questionN;
    while(Max-Min > 1){
        long long test=(Max+Min)/2;
        if(correctN-test*cons > wrongN*(cons-1)+cons-1)
            Min=test;
        else
            Max=test;
    }
    long long minScore=(2*cons*(powerMod(Max)-1))%MOD;
    minScore=(minScore+correctN-Max*cons)%MOD;
    printf("%I64d", minScore);
    return 0;
}