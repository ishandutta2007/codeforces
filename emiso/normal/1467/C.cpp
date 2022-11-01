#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n[3], ans, s[3], a[3][MN];
vector<ll> p[3];

int main() {
    scanf("%lld %lld %lld", &n[0], &n[1], &n[2]);

    for(int j = 0; j < 3; j++) {
        s[j] = 0;
        p[j].clear();
        for(int i = 0; i < n[j]; i++) {
            scanf("%lld", &a[j][i]);
            s[j] += a[j][i];
            p[j].push_back(a[j][i]);
        }
        sort(p[j].begin(), p[j].end());
    }

    int x = 1, y = 2, z = 0;
    if(n[x] == 1 || n[y] == 1) {
        ans = max(ans, s[z] + abs(s[x] - s[y]));
    } else {
        ans = max(ans, s[z] + abs(s[x] - p[x][0] - p[y][0]) + abs(s[y] - p[y][0] - p[x][0]));
    }

    x = 0, y = 2, z = 1;
    if(n[x] == 1 || n[y] == 1) {
        ans = max(ans, s[z] + abs(s[x] - s[y]));
    } else {
        ans = max(ans, s[z] + abs(s[x] - p[x][0] - p[y][0]) + abs(s[y] - p[y][0] - p[x][0]));
    }

    x = 0, y = 1, z = 2;
    if(n[x] == 1 || n[y] == 1) {
        ans = max(ans, s[z] + abs(s[x] - s[y]));
    } else {
        ans = max(ans, s[z] + abs(s[x] - p[x][0] - p[y][0]) + abs(s[y] - p[y][0] - p[x][0]));
    }

    printf("%lld\n", ans);
    return 0;
}
/*
10 1
5 5
5 1
*/