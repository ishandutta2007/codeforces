#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char s[5005];
int d[5005][5005] = {};
int cnt[5005];

int main() {
    scanf("%s", s);
    n = strlen(s);
    forn(c, n) {
        for (int i = c, j = c; i >= 0 && j < n && s[i] == s[j]; --i, ++j) {
            d[i][j] = 1;
            ++cnt[1];
        }
        for (int i = c, j = c + 1; i >= 0 && j < n && s[i] == s[j]; --i, ++j) {
            d[i][j] = 1;
            ++cnt[1];
        }
    }
    for (int len = 2; len <= n; ++len) {
        int half = len / 2;
        forn(i, n + 1 - len) {
            int j = i + len - 1;
            if (d[i][j] == 1) {
                d[i][j] = d[i][i + half - 1] + 1;
//                assert(d[i][j] == d[j - half + 1][j] + 1);
                --cnt[1];
                ++cnt[d[i][j]];
            }
        }
    }
    for (int i = n - 1; i >= 1; --i) {
        cnt[i] += cnt[i + 1];
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", cnt[i]);
    }
    puts("");
    return 0;
}