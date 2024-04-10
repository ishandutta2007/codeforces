#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, a, b;
int p = 0, q = 0;

void out() {
    int num = 1;
    while (p--) {
        forn(i, a - 1) {
            printf("%d ", num + 1 + i);
        }
        printf("%d ", num);
        num += a;
    }
    while (q--) {
        forn(i, b - 1) {
            printf("%d ", num + 1 + i);
        }
        printf("%d ", num);
        num += b;
    }
    puts("");
}

int main() {
    scanf("%d%d%d", &n, &a, &b);
    while ((p + 1) * a <= n) {
        ++p;
    }
    while (p >= 0) {
        while (p * a + (q + 1) * b <= n) {
            ++q;
        }
        if (p * a + q * b == n) {
            out();
            return 0;
        }
        --p;
    }
    cout << -1 << endl;
    return 0;
}