#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    long long ans=0;
    int pos=0;
    for(int i=0; i < m; ++i){
        int x;
        scanf("%d", &x);
        --x;
        ans += (x-pos+n)%n;
        pos=x;
    }
    printf("%I64d", ans);
    return 0;
}