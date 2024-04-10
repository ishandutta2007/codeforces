#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define fo(i, l, r) for(int i = l; i <= r; i ++)
using namespace std;
const int N = 2e6;
int n, m;
char s[N], a[N], b[N];
int nexta[N], nextb[N], tmp[N];
vector<int>g[N];
int f[N];
long long ff[N];
long long ans;
void getNext(char s[], int Next[], int n) {
    Next[0] = n;
    Next[1] = 0;
    while (s[1 + Next[1]] == s[Next[1]]) Next[1] ++;
    int x = 1;
    for (int i = 2; i < n ; i ++)
        if (Next[i - x] + i < Next[x] + x) {
            Next[i] = Next[i - x];
        } else {
            Next[i] = max(Next[x] + x - i, 0);
            while (s[Next[i]] == s[Next[i] + i]) Next[i]  ++;
            if (Next[i] + i >  Next[x] + x) x = i;
        }
}
void getExtend(char as[], char bs[], int Next[], int Extend[], int na, int nb) {
    getNext(as, Next, na);
    Extend[0] = 0;
    while (Extend[0] < na && Extend[0] < nb && as[Extend[0]] == bs[Extend[0]]) Extend[0] ++;
    int x = 0;
    for (int i = 1; i < nb; i ++)
        if (Next[i - x] + i < Extend[x] + x) {
            Extend[i] = Next[i - x];
        } else {
            Extend[i] = max(Extend[x] + x - i, 0);
            while (Extend[i] + i < nb && Extend[i] < na && as[Extend[i]] == bs[Extend[i] + i]) Extend[i]++;
            if (Extend[i] + i > Extend[x] + x) x = i;
        }
}
void ins(int x, int v) {
    while (x) {
        f[x] += v;
        x -= x & -x;
    }
}
int get(int x) {
    int v = 0;
    while (x <= m) {
        v += f[x];
        x += x & -x;
    }
    return v;
}
void insff(int x, int v) {
    while (x) {
        ff[x] += v;
        x -= x & -x;
    }
}
long long getff(int x) {
    long long v = 0;
    while (x <= m) {
        v += ff[x];
        x += x & -x;
    }
    return v;
}
int main() {
    scanf("%d %d", &n, &m);
    scanf("%s %s %s", a, b, s);
    getExtend(s, a, tmp, nexta, m, n);
    for (int i = 0; m - i - 1 > i; i ++)
        swap(s[i], s[m - i - 1]);
    for (int i = 0; n - i - 1 > i; i ++)
        swap(b[i], b[n - i - 1]);
    getExtend(s, b, tmp, nextb, m, n);
    for (int i = 0; n - i - 1 > i; i ++)
        swap(nextb[i], nextb[n - i - 1]);
    for (int i = 0; i < n ; i++)
        nexta[i] = min(nexta[i], m - 1), nextb[i] = min(nextb[i], m - 1);
    for (int i = 0; i < n; i ++) {
        ins(nexta[i], 1);
        insff(nexta[i], nexta[i]);
        if (i - (m - 1) >= 0)
            ins(nexta[i - (m - 1)], -1), insff(nexta[i - (m - 1)],  -nexta[i - (m - 1)]);
        ans += getff(max(m - nextb[i], 1))- 1ll * get(max(m - nextb[i], 1)) * (m - (nextb[i]) - 1);
    }
    printf("%lld\n", ans);
    return 0;
}