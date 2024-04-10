#include <bits/stdc++.h>
using namespace std;

typedef array<int, 1 << 16> arr;
const int P = 1000000007;
int n, m, lnk[510];
char s[510];

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    scanf("%s %d", s + 1, &m), n = strlen(s + 1);
    vector<int> st;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') st.push_back(i);
        if (s[i] == ')') lnk[st.back()] = i, st.pop_back();
    }
    auto FMT_AND = [&](arr &f, int type = 1) {
        for (int i = 0; i < 16; i++) {
            for (int S = 0; S < 1 << 16; S++) if (!(S >> i & 1)) {
                if (type) red(f[S] += f[S | (1 << i)] - P);
                else red(f[S] -= f[S | (1 << i)]);
            }
        }
    };
    auto FMT_OR = [&](arr &f, int type = 1) {
        for (int i = 0; i < 16; i++) {
            for (int S = 0; S < 1 << 16; S++) if (!(S >> i & 1)) {
                if (type) red(f[S | (1 << i)] += f[S] - P);
                else red(f[S | (1 << i)] -= f[S]);
            }
        }
    };
    function<arr(int, int)> solve = [&](int l, int r) {
        arr f{};
        if (l == r) {
            for (int i = 0; i < 8; i++) {
                if (s[l] != '?' && "abcdABCD"[i] != s[l]) continue;
                int S = 0;
                for (int v = 0; v < 16; v++) {
                    int a = v & 1, b = v >> 1 & 1, c = v >> 2 & 1, d = v >> 3 & 1;
                    if (array<int, 8>{!a, !b, !c, !d, a, b, c, d}[i]) S |= 1 << v;
                }
                f[S]++;
            }
            return f;
        }
        auto L = solve(l + 1, lnk[l] - 1), R = solve(lnk[l] + 3, r - 1);
        if (s[lnk[l] + 1] != '|') {
            arr A = L, B = R;
            FMT_AND(A), FMT_AND(B);
            for (int S = 0; S < 1 << 16; S++) f[S] = 1LL * A[S] * B[S] % P;
            FMT_AND(f, 0);
        }
        if (s[lnk[l] + 1] != '&') {
            FMT_OR(L), FMT_OR(R);
            for (int S = 0; S < 1 << 16; S++) L[S] = 1LL * L[S] * R[S] % P;
            FMT_OR(L, 0);
            for (int S = 0; S < 1 << 16; S++) red(f[S] += L[S] - P);
        }
        return f;
    };
    auto res = solve(1, n);
    int S = 0, T = 0, ans = 0;
    while (m--) {
        int a, b, c, d, e;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        int v = a | (b << 1) | (c << 2) | (d << 3);
        S |= 1 << v;
        if (e) T |= 1 << v;
    }
    for (int i = 0; i < 1 << 16; i++) {
        if ((i & S) == T) red(ans += res[i] - P);
    }
    printf("%d\n", ans);
    return 0;
}