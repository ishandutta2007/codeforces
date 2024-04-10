#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>

using namespace std;

long long int inp; 
 
long long int exp(long long int orig, long long int p, int mod) {
    if (p == 0) return 1;
    if (p == 1) return orig;
    
    long long temp = exp(orig,p/2,mod);
    long long sq = (temp*temp)%mod;
    
    if (p&1) sq = (sq*orig)%mod;
    
    return sq;
} 
 
int main()
{
    scanf("%I64d", &inp);
    inp = exp(2,inp,1000000007);
    printf("%I64d\n", ((inp*(inp+1))/2)%1000000007);
}