#include <stdio.h>
#include <map>
#define MOD 1000000007LL

using namespace std;

int n, k, d[32000];
long long nCr[2005][4015], mult;

void binom(int x){
    if(x > k-1){
        nCr[0][x]=0;
        return;
    }
    int a=x;
    for(int p=2; p*p <= a; ++p){
        if(a%p == 0){
            --d[p];
            a /= p;
            --p;
        }
    }
    --d[a];
    a=k-x;
    for(int p=2; p*p <= a; ++p){
        if(a%p == 0){
            ++d[p];
            a /= p;
            --p;
        }
    }
    if(a >= 32000)
        mult=(mult*a)%MOD;
    else
        ++d[a];
    nCr[0][x]=mult;
    for(int i=2; i < 32000; ++i)
        for(int j=0; j < d[i]; ++j)
            nCr[0][x]=(nCr[0][x]*i)%MOD;
}

long long in[2005];

int main()
{
    scanf("%d%d", &n, &k);
    if(!k){
        for(int i=0; i < n; ++i){
            for(int j=0; j < n; ++j)
                nCr[i][j]=0;
        }
        nCr[0][0]=1;
    }
    else{
        mult=1;
        nCr[0][0]=1;
        for(int i=1; i < 2*n+4; ++i){
            binom(i);
        }
        for(int i=0; i < n; ++i){
            nCr[i+1][0]=1;
            for(int j=0; j < 2*n+1-i; ++j){
                nCr[i+1][j+1]=(nCr[i][j]+nCr[i][j+1])%MOD;
            }
        }
    }
    for(int i=0; i < n; ++i){
        scanf("%I64d", in+i);
    }
    for(int i=0; i < n; ++i){
        long long k=0;
        for(int j=0; j <= i; ++j){
            k=(k+in[j]*nCr[i-j][i-j])%MOD;
        }
        printf("%I64d ", k);
    }
    return 0;
}