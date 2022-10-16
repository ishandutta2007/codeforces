#include <fstream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 100000;

char s[1 + MAXN], t[1 + MAXN];
int suma[1 + MAXN], sumb[1 + MAXN], suffixa[1 + MAXN], suffixb[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%s%s", s + 1, t + 1);
    int n = strlen(s + 1), m = strlen(t + 1), as = 0;
    for (int i = 1; i <= n; i++) {
        suma[i] = suma[i - 1] + (s[i] != 'A');
        if (s[i] == 'A')
            as++;
        else
            as = 0;
        suffixa[i] = as;
    }
    int bs = 0;
    for (int i = 1; i <= m; i++) {
        sumb[i] = sumb[i - 1] + (t[i] != 'A');
        if (t[i] == 'A')
            bs++;
        else
            bs = 0;
        suffixb[i] = bs;
    }
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int l1 = y1 - x1 + 1, l2 = y2 - x2 + 1;
        bool ok = true;
        int a1 = min(suffixa[y1], l1), a2 = min(suffixb[y2], l2), b1 = suma[y1] - suma[x1 - 1], b2 = sumb[y2] - sumb[x2 - 1];
        if (!b1 && b2) {
            b1 += 2;
            a1--;
            if ((b1 % 2) == (b2 % 2) && a1 >= a2)
                printf("1");
            else
                printf("0");
            continue;
        }
        if (b1 > b2) {
            printf("0");
            continue;
        }
        if (a1 < a2) {
            printf("0");
            continue;
        }
        if (b1 == b2) {
            if (a1 >= a2 && (a1 - a2) % 3 == 0)
                printf("1");
            else
                printf("0");
            continue;
        }
        a1 -= a2;
        a1 %= 3;
        if (a1)
            b1 += 2;
        if ((b2 - b1) % 2)
            printf("0");
        else
            printf("1");
    }
    return 0;
}