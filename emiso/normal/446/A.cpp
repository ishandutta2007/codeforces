#include <bits/stdc++.h>
#define MN 100010

using namespace std;

int n, arr[MN], l[MN], r[MN], ans, last;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    last = 1, l[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(arr[i] <= arr[i-1]) last = i;
        l[i] = (i - last + 1);
    }

    last = n, r[n] = 1;
    for(int i = n - 1; i > 0; i--) {
        if(arr[i] >= arr[i+1]) last = i;
        r[i] = (last - i + 1);
    }

    for(int i = 1; i <= n; i++) {
        ans = max(ans, 1 + l[i-1]);
        ans = max(ans, 1 + r[i+1]);
        if(arr[i+1] - arr[i-1] >= 2)
            ans = max(ans, l[i-1] + 1 + r[i+1]);
    }

    printf("%d\n", ans);
    return 0;
}