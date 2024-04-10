#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 5000;

char s[N + 1];
int  a[N];
bool v[N][N];

bool by_s(int i, int j)
{
    if (i == j) {
        return false;
    }
    while (s[i] == s[j]) {
        i ++;
        j ++;
    }
    return s[i] < s[j];
}

char at(int i, int p)
{
    return s[a[i] + p];
}

void solve(int l, int r, int p, int &rr)
{
    for (int i = l; i < r; ) {
        int j = i;
        while (j < r && at(i, p) == at(j, p)) {
            j ++;
        }
        if (at(i, p) != '\0') {
            for (int k = i; k < j; ++ k) {
                if (v[a[k]][a[k] + p]) {
                    rr --;
                    if (rr == 0) {
                        for (int i = 0; i <= p; ++ i) {
                            putchar(at(k, i));
                        }
                    }
                }
            }
            solve(i, j, p + 1, rr);
        }
        i = j;
    }
}

int main()
{
    int r;
    scanf("%s%d", s, &r);
    int n = strlen(s);
    memset(v, 0, sizeof(v));
    for (int i = n - 1; i >= 0; -- i) {
        for (int j = i; j < n; ++ j) {
            v[i][j] = s[i] == s[j];
            if (i + 2 <= j - 2) {
                v[i][j] &= v[i + 2][j - 2];
            }
        }
    }
    for (int i = 0; i < n; ++ i) {
        a[i] = i;
    }
    std::sort(a, a + n, by_s);
    solve(0, n, 0, r);
    return 0;
}