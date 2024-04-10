#include <bits/stdc++.h>
using namespace std;

int n, m, s, vis[100010];
long long t;

int main() {
    scanf("%d %d %d %lld", &n, &m, &s, &t);
    for (s--; t % n; t--) {
        s = s < m ? (s + t) % n : (s - t % n + n) % n;
    }
    memset(vis, -1, sizeof(vis)), vis[s] = 0;
    for (int $ = 1; t; vis[s] = $++) {
        for (int i = 0; i < n && t; i++, t--) {
            s = s < m ? (s + t) % n : (s - t % n + n) % n;
        }
        if (~vis[s]) t %= ($ - vis[s]) * n;
    }
    printf("%d\n", s + 1);
    return 0;
}