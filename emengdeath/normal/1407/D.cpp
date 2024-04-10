#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 3e5 + 10;
int g[N], h[N];
vector<int> w[N];
int n;
int d[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &h[i]);
    d[0] = 1;
    d[1] = 1;
    for (int i = 2; i <= n; i ++) {
        while (d[0] && h[d[d[0]]] < h[i]) d[0] --;
        if (d[0])
            w[i].push_back(d[d[0]]);
        d[++d[0]] = i;
    }
    d[0] = 1;
    d[1] = 1;
    for (int i = 2; i <= n; i ++) {
        while (d[0] && h[d[d[0]]] > h[i]) d[0] --;
        if (d[0])
            w[i].push_back(d[d[0]]);
        d[++d[0]] = i;
    }
    d[0] = 1;
    d[1] = n;
    for (int i = n - 1; i >= 1; i --) {
        while (d[0] && h[d[d[0]]] < h[i]) d[0] --;
        if (d[0])
            w[d[d[0]]].push_back(i);
        d[++d[0]] = i;
    }
    d[0] = 1;
    d[1] = n;
    for (int i = n - 1; i >= 1; i --) {
        while (d[0] && h[d[d[0]]] > h[i]) d[0] --;
        if (d[0])
            w[d[d[0]]].push_back(i);
        d[++d[0]] = i;
    }
    for (int i = 2; i <= n; i ++) {
        w[i].push_back(i - 1);
        sort(w[i].begin(), w[i].end());
        g[i] = 1e9;
        for (auto u:w[i])
            g[i] = min(g[i], g[u] + 1);
    }
    printf("%d", g[n]);
    return 0;
}