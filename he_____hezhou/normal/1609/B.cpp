#include <bits/stdc++.h>
using namespace std;
int n, q;
char s[100010];
int sum, qwq[100010];
inline void calc(int x) {
    if (x <= 0 || x + 2 > n) return;
    sum -= qwq[x];
    qwq[x] = s[x] == 'a' && s[x + 1] == 'b' && s[x + 2] == 'c';
    sum += qwq[x];
}
int main() {
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) calc(i);
    for (int i = 1; i <= q; i++) {
        int pos;
        char v[5];
        scanf("%d%s", &pos, v);
        s[pos] = v[0];
        calc(pos - 2), calc(pos - 1), calc(pos);
        printf("%d\n", sum);
    }
}