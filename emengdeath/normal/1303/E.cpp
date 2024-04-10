#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 411;
int f[N][N];
char s[N], t[N];
int a[N][26];
int T;
int n, m;
bool work(char * t1, int len1, char *t2, int len2) {
    for (int i = 0; i <= len1; i ++)
        for (int j = 0; j <= len2; j ++)
            f[i][j] = 1e9;
    f[0][0] = 0;
    for (int i = 0; i <= len1; i ++)
        for (int j = 0; j <= len2; j ++)
            if (f[i][j] <= n) {
                if (i != len1 && a[f[i][j]][t1[i + 1] - 'a'])
                    f[i+ 1][j] = min(f[i + 1][j], a[f[i][j]][t1[i + 1] - 'a']);
                if (j != len2 && a[f[i][j]][t2[j + 1] - 'a'])
                    f[i][j + 1] = min(f[i][j + 1], a[f[i][j]][t2[j + 1] - 'a']);
            }
    return f[len1][len2] <= n;
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%s", s + 1);
        scanf("%s", t + 1);
        n = strlen(s + 1);
        m = strlen(t + 1);
        memset(a, 0, sizeof(a));
        for (int i = n - 1; i >= 0; i --) {
            for (int j = 0; j < 26; j ++)
                a[i][j] = a[i+1][j];
            a[i][s[i + 1] - 'a'] = i + 1;
        }
        bool sig = 0;
        for (int i = 1; i <= m; i ++)
            sig |= work(t, i, t + i, m - i);
        sig?puts("YES"):puts("NO");
    }
    return 0;
}