#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, a[maxn], t[maxn], x[maxn];
vector<int> V;
map<int, int> mp[maxn];

void add(int k, int p, int v) {
    for (; p <= 1000000000; p += p & -p) mp[k][p] += v;
}

int sum(int k, int p) {
    int s = 0;
    for (; p; p -= p & -p) s += mp[k][p];
    return s;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &a[i], &t[i], &x[i]);
        V.push_back(x[i]);
    }
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    for (int i = 1; i <= n; i++) {
        x[i] = lower_bound(V.begin(), V.end(), x[i]) - V.begin();
        if (a[i] == 1) add(x[i], t[i], 1);
        if (a[i] == 2) add(x[i], t[i], -1);
        if (a[i] == 3) printf("%d\n", sum(x[i], t[i]));
    }
    return 0;
}