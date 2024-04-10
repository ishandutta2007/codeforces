#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m, a[MN], b[MN], ans;

void cant() {
    puts("-1");
    exit(0);
}

int main() {
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        ans += a[i] * m;
    }
    sort(a, a + n);
    for(int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }
    sort(b, b + m);

    if(a[n-1] > b[0]) cant();

    int j = m-1, i = n-1;
    while(j >= 0 && i >= 0) {
        for(int k = 1; k < m && j >= 0; k++) {
            ans += b[j] - a[i];
            j--;
        }
        if(j >= 0 && b[j] == a[i]) j--;
        i--;
    }

    if(j < 0) printf("%lld\n", ans);
    else cant();
    return 0;
}