#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef long double Double;

int n, r;
int x[1111];
Double y[1111];

int main() {
    scanf("%d%d", &n, &r);
    forn(i, n) scanf("%d", x + i);
    forn(i, n) {
        Double res = r;
        forn(j, i) {
            if (abs(x[i] - x[j]) == 2 * r) {
                res = max(res, y[j]);
                continue;
            }
            Double dist = 4 * (Double)r * r - Double(x[i] - x[j]) * (x[i] - x[j]);
            if (dist > 0) {
                res = max(res, y[j] + sqrt(dist));
            }
        }
        y[i] = res;
    }
    forn(i, n) printf("%.15f ", (double)y[i]);
    puts("");
    return 0;
}