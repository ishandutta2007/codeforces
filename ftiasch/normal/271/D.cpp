#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>

#define ALL(v) (v).begin(), (v).end()

const int N = 1501;

int  k, lcp[N][N];
char s[N], good[27];

struct Substring {
    Substring(int l, int r) : l(l), s(r - l) {}

    int l, s;
};

bool operator < (const Substring &u, const Substring &v) {
    int l = std::min(lcp[u.l][v.l], std::min(u.s, v.s));
    char a = l < u.s ? s[u.l + l] : 0;
    char b = l < v.s ? s[v.l + l] : 0;
    return a < b;
}

bool operator == (const Substring &u, const Substring &v) {
    return !(u < v || v < u);
}

int main() {
    scanf("%s%s%d", s, good, &k);
    memset(lcp, 0, sizeof(lcp));
    int n = strlen(s);
    for (int i = n - 1; i >= 0; -- i) {
        for (int j = n - 1; j >= 0; -- j) {
            if (s[i] == s[j]) {
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
            }
        }
    }
    std::vector<Substring> substrings;
    for (int i = 0; i < n; ++ i) {
        int count = 0;
        for (int j = i; j < n; ++ j) {
            count += '1' - good[s[j] - 'a'];
            if (count > k) {
                break;
            }
            substrings.push_back(Substring(i, j + 1));
        }
    }
    std::sort(ALL(substrings));
    printf("%d\n", static_cast<int>(std::unique(ALL(substrings)) - substrings.begin()));
    return 0;
}