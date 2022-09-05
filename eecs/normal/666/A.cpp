#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;
int n, f[maxn][2];
char s[maxn];

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = n; i; i--) {
        if (i + 1 <= n && (i + 1 == n || f[i + 2][1] || f[i + 2][0] && (s[i] != s[i + 2] || s[i + 1] != s[i + 3]))) {
            f[i][0] = 1;
        }
        if (i + 2 <= n && (i + 2 == n || f[i + 3][0] || f[i + 3][1] && (s[i] != s[i + 3] || s[i + 1] != s[i + 4] || s[i + 2] != s[i + 5]))) {
            f[i][1] = 1;
        }
    }
    set<string> S;
    for (int i = n; i > 5; i--) {
        if (f[i][0]) {
            string tmp = {s[i], s[i + 1]};
            S.insert(tmp);
        }
        if (f[i][1]) {
            string tmp = {s[i], s[i + 1], s[i + 2]};
            S.insert(tmp);
        }
    }
    printf("%d\n", S.size());
    for (auto s : S) printf("%s\n", s.c_str());
    return 0;
}