#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int h, hh, a, b;

int main() {
    scanf("%d%d%d%d", &h, &hh, &a, &b);
    if (h + a * 8 >= hh) {
        printf("0\n");
        return 0;
    }
    if (a <= b) {
        printf("-1\n");
        return 0;
    }
    h += a * 8;
    h -= b * 12;
    int cnt = 0;
    while (true) {
        ++cnt;
        h += a * 12;
        if (h >= hh) {
            printf("%d\n", cnt);
            return 0;
        }
        h -= b * 12;
    }
    return 0;
}