#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const double EPS = 1e-7;
int k, q;
double d[1001];
int p[1000], ord[1000], ans[1000];

inline bool cmp(const int &lhs, const int &rhs) {
    return p[lhs] < p[rhs];
}

int main() {
    scanf("%d%d", &k, &q);
    forn(i, q) {
        scanf("%d", p + i);
        ord[i] = i;
    }
    sort(ord, ord + q, cmp);
    d[0] = 1;
    int iter = 0;
    int ind = 0;
    while (ind < q) {
        ++iter;
        for (int i = k - 1; i >= 0; --i) {
            d[i + 1] += d[i] * (k - i) / k;
            d[i] = d[i] * i / k;
            if (d[i] < 1e-50) {
                d[i] = 0;
            }
        }
        while (ind < q) {
            if ((p[ord[ind]] - EPS) / 2000.0 > d[k]) {
                break;
            }
            ans[ord[ind]] = iter;
            ++ind;
        }
    }
    forn(i, q) {
        printf("%d\n", ans[i]);
    }
    return 0;
}