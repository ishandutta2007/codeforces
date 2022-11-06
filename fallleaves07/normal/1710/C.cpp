#include<bits/stdc++.h>
using LL = long long;
const int N = 2e5 + 5, M = 998244353;

int mod(int val) {
    return (val < 0) ? (val + M) : ((val >= M) ? (val - M) : val);
}

std::string s;
int f[N][8][8];
bool vis[N][8][8];
int solve(int l, int dtag, int stag) {
    if (l == (int)s.length()) {
        return stag == 7 ? 1 : 0;
    }
    if (vis[l][dtag][stag]) {
        return f[l][dtag][stag];
    }
    vis[l][dtag][stag] = true;
    int &ret = f[l][dtag][stag];
    ret = 0;
    for (int i = 0; i < 8; i++) {
        int a = i >> 2, b = (i >> 1) & 1, c = i & 1;
        int nd = dtag, ns = stag;
        if (s[l] == '0') {
            if (!(dtag >> 2) && a) {
                continue;
            }
            if (!((dtag >> 1) & 1) && b) {
                continue;
            }
            if (!(dtag & 1) && c) {
                continue;
            }
        } else {
            if (a == 0) {
                nd |= 4;
            }
            if (b == 0) {
                nd |= 2;
            }
            if (c == 0) {
                nd |= 1;
            }
        }
        if (a != b && a != c) {
            ns |= 4;
        }
        if (b != a && b != c) {
            ns |= 2;
        }
        if (c != a && c != b) {
            ns |= 1;
        }
        ret = mod(ret + solve(l + 1, nd, ns));
    }
    return ret;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> s;
    printf("%d\n", solve(0, 0, 0));
    return 0;
}