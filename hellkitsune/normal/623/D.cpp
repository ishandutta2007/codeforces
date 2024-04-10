#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef long double Double;

int n;
int pp[100];
Double p[100];
Double cur[100] = {};
Double ans = 0;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", pp + i), p[i] = 0.01 * pp[i];
    REP(i, n) cur[i] = 0;
    Double pre = 0;
    REP(times, 1000000) {
        int mn = -1;
        Double best = -1;
        if (times < n) mn = times;
        if (mn == -1) REP(i, n) {
            Double x = (1 - cur[i]) * p[i];
            x = (cur[i] + x) / cur[i];
            if (x > best) {
                best = x;
                mn = i;
            }
        }
        cur[mn] += (1 - cur[mn]) * p[mn];
        Double tot = 1;
        REP(i, n) tot *= cur[i];
        ans += (tot - pre) * (times + 1);
        pre = tot;
    }
    printf("%.15f\n", (double)ans);
    return 0;
}