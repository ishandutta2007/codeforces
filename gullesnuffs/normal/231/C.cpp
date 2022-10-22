#include <stdio.h>
#include <algorithm>

using namespace std;

int n, add;
long long x[100005];

int main()
{
    scanf("%d%d", &n, &add);
    for(int i=0; i < n; ++i){
        scanf("%I64d", x+i);
    }
    sort(x, x+n);
    long long start=0, stop=0, best=0, ans=0, sum=0;
    for(int i=0; i < n; ++i){
        if(i > 0)
            sum += (stop-start)*(x[i]-x[i-1]);
        ++stop;
        while(sum > add){
            sum -= x[i]-x[start];
            ++start;
        }
        if(stop-start > best){
            best=stop-start;
            ans=x[i];
        }
    }
    int a=best, b=ans;
    printf("%d %d", a, b);
    return 0;
}