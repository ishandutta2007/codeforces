#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int maxn = 800010, N = 800005, P = 1000000007;
int n, m, h[maxn], prel[maxn], sufl[maxn], len1[maxn], len2[maxn];
pair<int, int> q[maxn];
ull val[maxn], pre[maxn], suf[maxn];
vector<pair<int, int>> Q1[maxn], Q2[maxn];

namespace BIT1 {
int c[maxn << 1];
ull s[maxn << 1];

void add(int p, int len, ull v) {
    for (p++; p <= N; p += p & -p) {
        if (c[p] < len) c[p] = len, s[p] = v;
        else if (c[p] == len) (s[p] += v) %= P;
    }
}

pair<int, ull> query(int p) {
    int len = 0;
    ull v = 0;
    for (p++; p; p -= p & -p) {
        if (c[p] > len) len = c[p], v = s[p];
        else if (c[p] == len) (v += s[p]) %= P;
    }
    return make_pair(len, v);
}
}  // namespace BIT1

namespace BIT2 {
int c[maxn << 1];
ull s[maxn << 1];

void add(int p, int len, ull v) {
    for (p++; p; p -= p & -p) {
        if (c[p] < len) c[p] = len, s[p] = v;
        else if (c[p] == len) (s[p] += v) %= P;
    }
}

pair<int, ull> query(int p) {
    int len = 0;
    ull v = 0;
    for (p++; p <= N; p += p & -p) {
        if (c[p] > len) len = c[p], v = s[p];
        else if (c[p] == len) (v += s[p]) %= P;
    }
    return make_pair(len, v);
}
}  // namespace BIT2

int main() {
    scanf("%d %d", &n, &m);
    vector<int> V;
    mt19937_64 rnd(time(0));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]), V.push_back(h[i]);
        val[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &q[i].first, &q[i].second);
        V.push_back(q[i].second);
    }
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    for (int i = 1; i <= m; i++) {
        q[i].second = lower_bound(V.begin(), V.end(), q[i].second) - V.begin() + 1;
        Q1[q[i].first].emplace_back(q[i].second, i);
        Q2[q[i].first].emplace_back(q[i].second, i);
    }
    BIT1::add(0, 0, 1);
    for (int i = 1; i <= n; i++) {
        h[i] = lower_bound(V.begin(), V.end(), h[i]) - V.begin() + 1;
        for (auto p : Q1[i]) {
            prel[p.second] = BIT1::query(p.first - 1).first;
        }
        auto p = BIT1::query(h[i] - 1);
        len1[i] = p.first, pre[i] = p.second * val[i] % P;
        BIT1::add(h[i], p.first + 1, pre[i]);
    }
    auto foo = BIT1::query(800001);
    int max_len = foo.first;
    ull all = foo.second;
    BIT2::add(800001, 0, 1);
    for (int i = n; i; i--) {
        for (auto p : Q2[i]) {
            sufl[p.second] = BIT2::query(p.first + 1).first;
        }
        auto p = BIT2::query(h[i] + 1);
        len2[i] = p.first, suf[i] = p.second;
        BIT2::add(h[i], p.first + 1, suf[i] * val[i] % P);
    }
    assert(foo == BIT2::query(0));
    for (int i = 1; i <= m; i++) {
        int v = max_len;
        if (len1[q[i].first] + len2[q[i].first] + 1 == max_len && pre[q[i].first]
            * suf[q[i].first] % P == all) v--;
        printf("%d\n", max(v, prel[i] + sufl[i] + 1));
    }
    return 0;
}