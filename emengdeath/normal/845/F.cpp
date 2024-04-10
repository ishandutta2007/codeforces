#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int mod = 1e9 + 7;
int f[2][1<<15][2][2];
char s[251][251], s1[251][251];
int n, m;
int add(int x, int y) {
    x+= y;
    return x >= mod ?x - mod : x;
}
int sub(int x, int y) {
    x -= y;
    return x < 0 ? x +mod : x;
}
int mul(int x, int y){
    return 1ll * x * y % mod;
}
bool isempty(int x, int y) {
    if (x < 0 || y < 0 || x >= n && y >= m) return 1;
    return s[x][y] =='.';
}

bool iswall(int x, int y) {
    if (x < 0 || y < 0 || x >= n && y >= m) return 0;
    return s[x][y] =='x';
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            scanf(" %c", &s1[i][j]);
    if (n >= m) {
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                s[i][j] = s1[i][j];
    } else {
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                s[j][i] = s1[i][j];
        swap(n, m);
    }
    f[0][0][0][0] = 1;
    bool bz = 0, bz1 = 1;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++, swap(bz, bz1))
            for (int st = 0; st < (1 << m); st ++)
                for (int left = 0; left < 2; left ++)
                    for (int empty = 0;empty < 2; empty ++)
                        if (f[bz][st][left][empty]) {
                            int v = f[bz][st][left][empty];
                            f[bz][st][left][empty] = 0;
                            int r = isempty(i, j);
                            for (int k = 0; k <= r; k ++) {
                                int st1 = ((st & ((1 << (m - 1)) - 1)) << 1) | (k || iswall(i,j)||(isempty(i - 1, j) && (st >> (m - 1))));
                                int left1 = (left && isempty(i, j)) || k;
                                int empty1 = empty + (!left && !(st1 & 1));
                                if (empty1 > 1) continue;
                                f[bz1][st1][left1][empty1] = add(f[bz1][st1][left1][empty1], v);
                            }
                        }
        for (int st = 0; st < (1 << m); st ++)
            for (int left = 1; left < 2; left ++)
                for (int empty = 0;empty < 2; empty ++)
                    if (f[bz][st][left][empty]) {
                        f[bz][st][0][empty] = add(f[bz][st][0][empty], f[bz][st][left][empty]);
                        f[bz][st][left][empty] = 0;
                    }
    }
    int ans = 0;
    for (int st = 0; st < (1<<m); st++)
        for (int empty = 0;empty < 2; empty ++)
            ans = add(ans, f[bz][st][0][empty]);
    printf("%d\n", ans);
    return 0;
}