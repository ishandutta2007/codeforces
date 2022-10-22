#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

long long s[100005];

int main()
{
    long long n, d;
    scanf("%I64d%I64d", &n, &d);
    for(int i=0; i < n; ++i){
        scanf("%I64d", s+i);
    }
    long long start=0;
    long long ans=0;
    for(long long j=2; j < n; ++j){
        while(s[j]-s[start] > d)
            ++start;
        if(j-start-1 > 0)
            ans += ((j-start-1)*(j-start))/2;
    }
    printf("%I64d", ans);
    return 0;
}