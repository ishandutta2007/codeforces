#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 3e5;
int sum[N][26];
int n, m;
char s[N];
int main() {
    scanf("%s", s+ 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < 26; j ++)
            sum[i][j] = sum[i - 1][j];
        sum[i][s[i] - 'a'] ++;
    }
    scanf("%d", &m);
    while (m --) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (y - x + 1 == 1) {
            puts("Yes");
            continue;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i ++)
            if (sum[y][i] - sum[x - 1][i]) {
                cnt ++;
            }
        if (cnt > 2 || (cnt == 2 && s[y] != s[x]))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}