#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
char s[N], t[N];
int f[2][N];
int Next[N], A[N][26];
int main() {
    scanf("%s", s);
    scanf("%s", t);
    int n = strlen(t);
    int m = strlen(s);
    Next[0] = 0;
    for (int i=1, j = 0 ;i<n;i++){
        while (j && t[i] != t[j]) j = Next[j - 1];
        if (t[i] == t[j]) j ++;
        Next[i] = j;
    }
    for (int i = 0; i <= n; i ++)
        for (int j = 0; j < 26; j ++)
            if (i < n && t[i] == 'a' + j) {
                A[i][j] = i + 1;
            } else {
                if (i == 0)
                    A[i][j] = 0;
                else
                    A[i][j] = A[Next[i-1]][j];
            }
    bool bz = 0, bz1 = 1;
    f[bz][0] = 1;
    for (int i = 0; i < m; i ++, swap(bz1, bz))
        for (int j = 0; j <= n; j ++)
            if (f[bz][j]) {
                int l = 0, r = 25;
                if (s[i] != '?')
                    l = r = s[i] - 'a';
                int v = (j == n) + f[bz][j];
                for (int k = l; k <= r;k ++)
                    f[bz1][A[j][k]] = max(f[bz1][A[j][k]], v);
                f[bz][j] = 0;
            }
    int ans = 0;
    for (int i = 0; i <= n; i ++)
        ans = max(ans, f[bz][i] + (f[bz][i] && i == n));
    printf("%d\n", ans - 1);
    return 0;
}