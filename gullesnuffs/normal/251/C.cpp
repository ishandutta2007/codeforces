#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    long long a, b;
    long long k;
    scanf("%I64d%I64d%I64d", &a, &b, &k);
    int moves360360=0;
    for(long long n=360360; n > 0; ++moves360360){
        long long Min=n-1;
        for(long long i=k/2+1; i <= k; ++i){
            if(n-(n%i) < Min)
                Min=n-(n%i);
        }
        n=Min;
    }
    long long moves=0;
    for(long long n=a; n > b; ){
        long long Min=n-1;
        for(long long i=2; i <= k; ++i){
            if(n-(n%i) < Min && n-(n%i) >= b)
                Min=n-(n%i);
        }
        n=Min;
        ++moves;
        if(n%360360LL == 0){
            long long times=(n-b-1)/360360LL;
            moves += times*moves360360;
            n -= 360360LL*times;
        }
    }
    printf("%I64d", moves);
    return 0;
}