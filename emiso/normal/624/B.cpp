#include <stdio.h>
#include <algorithm>

using namespace std;

long long ans = 0,a[28],last = 999999999999;

inline long long minn (long long a, long long b) {
    return (a<b)?a:b;
}

int main()
{
    int n;

    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%I64d",&a[i]);
    }
    sort(a,a+n);

    for(int i = n-1; i >=0; i--) {
        ans += minn(last,a[i]);
        last = minn(last,a[i]) - 1;
        if(last < 0) last = 0;
    }

    printf("%I64d\n",ans);
    return 0;
}