#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
const double beta = 0.8;
int n, m, cnt[maxn];
double p[maxn], pw[10010];
char s[maxn], t[2];
mt19937 rnd(time(0));

int main() {
    scanf("%d %d", &n, &m);
    for (int i = pw[0] = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * beta;
    }
    while (m--) {
        scanf("%s", s + 1);
        double s0 = 0, all = 0;
        int mn = *min_element(cnt + 1, cnt + n + 1);
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') s0 += pw[cnt[i] - mn];
            all += pw[cnt[i] - mn];
        }
        if (uniform_real_distribution<double>(0, all)(rnd) < s0) puts("0"), fflush(stdout);
        else puts("1"), fflush(stdout);
        scanf("%s", t);
        for (int i = 1; i <= n; i++) {
            if (s[i] ^ t[0]) cnt[i]++;
        }
    }
    return 0;
}