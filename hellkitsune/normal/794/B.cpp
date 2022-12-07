#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef long double Double;

int n;
Double h;

int main() {
    cin >> n >> h;
    Double s = h / n;
    Double pos = 0;
    forn(i, n - 1) {
        Double lo = pos, hi = h, mid;
        forn(_, 120) {
            mid = (Double)0.5 * (lo + hi);
            if ((mid - pos) * (pos + mid) / h < s) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        printf("%.15f ", (double)lo);
        pos = lo;
    }
    return 0;
}