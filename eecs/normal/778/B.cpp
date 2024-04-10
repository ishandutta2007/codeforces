#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010, maxm = 1010;
int n, m, cnt[2], num[maxn], id1[maxn], id2[maxn];
char var[maxn][11], foo[maxn][maxm], bar[maxn][11], op[maxn][5];
string str;
map<string, int> mp;

int main() {
    scanf("%d %d", &n, &m);
    mp["?"] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%s %*s %s", var[i], foo[i]), str.clear();
        for (int j = 0, $ = strlen(var[i]); j < $; j++) {
            str.push_back(var[i][j]);
        }
        mp[str] = i;
        if (!isdigit(foo[i][0])) {
            scanf("%s %s", op[i], bar[i]);
            str.clear();
            for (int j = 0, $ = strlen(foo[i]); j < $; j++) {
                str.push_back(foo[i][j]);
            }
            id1[i] = mp[str], str.clear();
            for (int j = 0, $ = strlen(bar[i]); j < $; j++) {
                str.push_back(bar[i][j]);
            }
            id2[i] = mp[str];
        }
    }
    string s, t;
    for (int i = 0; i < m; i++) {
        memset(cnt, 0, sizeof(cnt));
        for (int c : {0, 1}) {
            num[0] = c;
            for (int j = 1; j <= n; j++) {
                if (!isdigit(foo[j][0])) {
                    int x = num[id1[j]], y = num[id2[j]];
                    if (op[j][0] == 'A') num[j] = x & y;
                    if (op[j][0] == 'O') num[j] = x | y;
                    if (op[j][0] == 'X') num[j] = x ^ y;
                } else {
                    num[j] = foo[j][i] == '1' ? 1 : 0;
                }
                cnt[c] += num[j];
            }
        }
        if (cnt[0] <= cnt[1]) s.push_back('0');
        else s.push_back('1');
        if (cnt[0] >= cnt[1]) t.push_back('0');
        else t.push_back('1');
    }
    printf("%s\n%s\n", s.c_str(), t.c_str());
    return 0;
}