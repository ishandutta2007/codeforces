#include <stdio.h>
#include <algorithm>
#define mod 1000000007

using namespace std;

char x[105];
long long p[205];

int main()
{
    scanf("%s", x);
    long long ans = 0;
    int n;
    for(int i=0; x[i]; ++i)n = i;
    p[0] = 1;
    for(int i=0; i < 202; ++i)
        p[i+1] = (p[i] * 2) % mod;
    ++n;
    for(int i=0; i < n; ++i){
        if(x[i] == '0'){
            
        }
        else{
            ans = (ans + p[i] * p[2*(n-i-1)]) % mod;
        }
    }
    printf("%I64d", ans);
    return 0;
}