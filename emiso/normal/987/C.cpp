#include <bits/stdc++.h>

using namespace std;

int n, s[3030], c[3030];
long long best[3030];

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    for(int i = 0; i < n; i++) {
        best[i] = INT_MAX;
        for(int j = i + 1; j < n; j++) {
            if(s[j] > s[i]) best[i] = min(best[i], 0LL + c[j]);
        }

    }

    long long cost = INT_MAX;
    for(int i = 0; i + 2 < n; i++)
        for(int j = i + 1; j + 1 < n; j++)
            if(s[i] < s[j])
                cost = min(cost, best[j] + c[j] + c[i]);

    if(cost < INT_MAX) printf("%lld\n", cost);
    else printf("-1\n");
    return 0;
}