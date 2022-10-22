#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
long long a[100005];
long long sum=0;

long long gcd(long long a, long long b){
    return b?gcd(b, a%b):a;
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i < n; ++i){
        scanf("%I64d", a+i);
    }
    sort(a, a+n);
    for(long long i=0; i < n; ++i){
        if(i < n-1)
            sum += (a[i+1]-a[i])*(i+1)*(n-i-1);
    }
    sum *= 2;
    for(int i=0; i < n; ++i)
        sum += a[i];
    long long g=gcd(sum, n);
    printf("%I64d %I64d\n", sum/g, n/g);
    return 0;
}