#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[26], g;
char s[100005];

int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    int sum = 0;
    REP(i, n) sum += a[i];
    int g = 0;
    REP(i, n) g = gcd(g, a[i]);
    REP(i, n) a[i] /= g;
    int oc = 0;
    REP(i, n) if (a[i] % 2 == 1) ++oc;
    if (oc > 1 && g % 2 == 1) {
        printf("0\n");
        REP(i, n) REP(j, a[i] * g) printf("%c", char('a' + i));
        printf("\n");
        return 0;
    }
    int cnt = 0;
    REP(i, n) REP(j, a[i] / 2) s[cnt++] = 'a' + i;
    REP(i, n) if (a[i] % 2 == 1) s[cnt++] = 'a' + i;
    for (int i = n - 1; i >= 0; --i) REP(j, a[i] / 2) s[cnt++] = 'a' + i;
    if (oc > 1) {
        REP(i, cnt) s[i + cnt] = s[i];
        reverse(s, s + cnt);
        cnt *= 2;
    }
    for (int i = cnt; i < sum; ++i) s[i] = s[i - cnt];
    s[sum] = '\0';
    printf("%d\n", g);
    printf("%s\n", s);
    return 0;
}