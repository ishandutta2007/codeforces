#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, u, e[101010];

int main() {
    scanf("%d %d", &n, &u);

    for(int i = 0; i < n; i++) {
        scanf("%d", &e[i]);
    }

    int f = 0;
    double best = 0;

    for(int i = 0; i < n; i++) {
        int j = upper_bound(e, e + n, e[i] + u) - e - 1;
        if(i + 2 > j) continue;
        f = 1;
        best = max(best, (0.0 + e[j] - e[i+1]) / (e[j] - e[i]));
    }

    if(f) printf("%.9f\n", best);
    else printf("-1");
    return 0;
}