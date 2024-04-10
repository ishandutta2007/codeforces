#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 1000000007;
int n, q, g = 1, a[maxn];
multiset<int> S[maxn];
map<int, int> mp[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        for (int j = 2; j * j <= a[i]; j++) if (!(a[i] % j)) {
            int c = 0;
            while (!(a[i] % j)) a[i] /= j, c++;
            S[j].insert(c), mp[i][j] = c;
        }
        if (a[i] > 1) S[a[i]].insert(1), mp[i][a[i]] = 1;
    }
    for (int i = 1; i <= 200000; i++) if (S[i].size() == n) {
        g = 1LL * g * qp(i, *S[i].begin()) % P;
    }
    auto get = [&](int x) {
        return S[x].size() == n ? *S[x].begin() : 0;
    };
    while (q--) {
        int i, x; scanf("%d %d", &i, &x);
        for (int j = 2; j * j <= x; j++) if (!(x % j)) {
            int c = 0;
            while (!(x % j)) x /= j, c++;
            int foo = get(j);
            if (mp[i].find(j) != mp[i].end()) S[j].erase(S[j].find(mp[i][j]));
            S[j].insert(mp[i][j] += c);
            int bar = get(j) - foo;
            while (bar--) g = 1LL * g * j % P;
        }
        if (x > 1) {
            int foo = get(x);
            if (mp[i].find(x) != mp[i].end()) S[x].erase(S[x].find(mp[i][x]));
            S[x].insert(++mp[i][x]);
            int bar = get(x) - foo;
            while (bar--) g = 1LL * g * x % P;
        }
        printf("%d\n", g);
    }
    return 0;
}