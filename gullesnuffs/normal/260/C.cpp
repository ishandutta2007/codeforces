#include <stdio.h>

using namespace std;

long long a[100005];

int main()
{
    long long n, x;
    scanf("%I64d%I64d", &n, &x);
    --x;
    long long Min=1000000005LL, MinPos=0;
    bool first=1;
    for(int i=0; i < n; ++i)
        scanf("%I64d", a+i);
    for(int i=(x+1)%n; i != (x+1)%n || first; i=(i+1)%n){
        first=0;
        if(a[i] <= Min){
            Min=a[i];
            MinPos=i;
        }
    }
    long long sum=0;
    for(int i=(MinPos+1)%n; i != (x+1)%n; i=(i+1)%n){
        sum += 1;
        --a[i];
    }
    for(int i=0; i < n; ++i){
        if(i != MinPos)
            a[i] -= a[MinPos];
    }
    sum += n*a[MinPos];
    a[MinPos]=sum;
    for(int i=0; i < n; ++i)
        printf("%I64d ", a[i]);
    return 0;
}