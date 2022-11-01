#include <bits/stdc++.h>

#define MN 1001000

using namespace std;

int n, ans, a[MN], b[MN];

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%1d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%1d", &b[i]);
    }

    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) continue;
        ans++;
        if(i + 1 < n)
            if(a[i] != a[i+1] && a[i+1] != b[i+1])
                i++;
    }

    printf("%d\n", ans);
    return 0;
}