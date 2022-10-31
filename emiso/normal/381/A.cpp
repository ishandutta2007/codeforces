#include <bits/stdc++.h>

using namespace std;

int n, x, arr[1010], l, r, sum[2], t;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        arr[i] = x;
    }

    l = 0, r = n - 1;
    while(l <= r) {
        if(arr[l] > arr[r]) {
            sum[t] += arr[l];
            l++;
        }

        else {
            sum[t] += arr[r];
            r--;
        }

        t = 1 - t;
    }

    printf("%d %d\n", sum[0], sum[1]);

    return 0;
}