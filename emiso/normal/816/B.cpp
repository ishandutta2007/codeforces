#include <bits/stdc++.h>
#define MN 200200

using namespace std;

int a[MN], b[MN], c[MN], n, k, q, l, r, ans;

int main() {
    scanf("%d %d %d", &n, &k, &q);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &l, &r);
        a[l] += 1;
        a[r + 1] -= 1;
    }

    for(int i=1; i<MN; i++) {
        b[i] = b[i-1] + a[i];
    }

    for(int i=1; i<MN; i++) {
        c[i] = c[i-1];
        if(b[i] >= k) c[i]++;
    }

    for(int i=0; i<q; i++) {
        scanf("%d %d", &l, &r);
        printf("%d\n", c[r] - c[l-1]);
    }
    return 0;
}