#include <bits/stdc++.h>

#define MAXN 3030
using namespace std;

int bit[MAXN], ans;
int n, a[MAXN];

void update(int idx, int delta) {
    for(; idx < MAXN; idx += (idx & -idx)) bit[idx] += delta;
}

int read(int idx) {
    int sum = 0;
    for(; idx; idx -= (idx & -idx)) sum += bit[idx];
    return sum;
}

int main() {
    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++) {
        ans += (1LL * i - read(a[i]));
        update(a[i],1);
    }

    printf("%.9f\n", ans / 2 * 4 + (ans % 2) + 0.0);

    return 0;
}