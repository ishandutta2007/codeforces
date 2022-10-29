#include <algorithm>
#include <cstdio>
#include <bitset>
using namespace std;
const int N = 160;
int n, m;
pair<int, pair<int, int> > d[N];
bitset<N> f, ta[N], tb[N], a[N], tta, b[N];
void update(bitset<N>*a, bitset<N>*b, bitset<N>* c) {
    for (int i = 0; i < n; i ++)
        ta[i] = a[i], tb[i] = b[i], c[i].reset();
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            if (ta[i][j])
                c[i] |= tb[j];
}
void update1(bitset<N>&a, bitset<N>*b, bitset<N>& c) {
    tta = a;
    c.reset();
    for (int i = 0; i < n; i ++)
        if (tta[i])
            c |= b[i];
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++)
        scanf("%d %d %d", &d[i].second.first, &d[i].second.second, &d[i].first), d[i].second.first --, d[i].second.second --;
    sort(d + 1, d + m + 1);
    int l = 1;
    f[0] = 1;
    int t = 0;
    int cnt = 0;
    while (l <= m || cnt < n) {
        while (l <= m && d[l].first == t) {
            a[d[l].second.first][d[l].second.second] = 1;
            l ++;
            cnt = 0;
        }
        if (cnt < n) {
            ++cnt;
            ++ t;
            update1(f, a, f);
            if (f[n - 1]) break;
        } else {
            int step = d[l].first - t;
            for (int i = 0; i < n; i ++) b[i] = a[i];
            for (int i = 0; (step >> i); i ++)
            {
                if ((step >> i) & 1)update1(f, b, f);
                update(b, b, b);
            }
            t = d[l].first;
        }
    }
    if (f[n - 1]) printf("%d\n", t);
    else puts("Impossible");
    return 0;
}