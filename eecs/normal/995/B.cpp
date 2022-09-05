#include <bits/stdc++.h>
using namespace std;

const int maxn = 210;
int n, a[maxn], c[maxn];
vector<int> T, V[maxn];

void add(int p) {
    for (; p <= 2 * n; p += p & -p) c[p]++;
}

int sum(int p) {
    int s = 0;
    for (; p; p -= p & -p) s += c[p];
    return s;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n * 2; i++) {
        scanf("%d", &a[i]);
        if (V[a[i]].empty()) T.push_back(a[i]);
        V[a[i]].push_back(i);
    }
    int tot = 0, ans = 0;
    for (int x : T) for (int i : V[x]) {
        ans += tot - sum(i);
        add(i), tot++;
    }
    printf("%d\n", ans);
    return 0;
}