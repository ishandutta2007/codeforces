#include <bits/stdc++.h>

using namespace std;

int n, k, a[200020];

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);

    int l = 0, r = n/2, m;
    while(l < r) {
        m = (l + r + 1) / 2;

        int flag = 1;
        for(int i = 0; flag && i < m; i++)
            if(a[i] + k > a[n-m+i]) flag = 0;

        if(flag) l = m;
        else r = m - 1;
    }

    printf("%d\n", l);
    return 0;
}