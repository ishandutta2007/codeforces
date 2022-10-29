#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
char s[N];
int n;
int d[N];
char r[N];
char ans[N][11];
int len[N];
int main() {
    scanf("%s", s);
    n = strlen(s);
    for (int i = n - 1; i >= 0; i --) {
        if (d[0] && d[d[0]] == i + 1 && s[d[d[0]]] == s[i] && (d[0] == 1 || r[d[0]] < s[d[d[0]]]))
            d[0] --;
        else {
            d[++d[0]] = i;
            if (d[0] > 1)
            {
                if (s[d[d[0]]] == s[d[d[0] - 1]]) r[d[0]] = r[d[0] - 1];
                else
                    r[d[0]] = s[d[d[0] - 1]];
            }
        }
        if (d[0] <= 10) {
            for (int j = 0; j < d[0]; j ++)
                ans[i][j] = s[d[d[0] - j]];
        } else {
            for (int j = 0; j < 5; j ++)
                ans[i][j] = s[d[d[0] - j]];
            ans[i][5] = ans[i][6] = ans[i][7] = '.';
            ans[i][8] = s[d[2]];
            ans[i][9] = s[d[1]];
        }
        len[i] = d[0];
    }
    for (int i = 0; i < n; i ++)
        printf("%d %s\n", len[i], ans[i]);
    return 0;
}