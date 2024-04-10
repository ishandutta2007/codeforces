#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef DEBUG
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

using namespace std;

const int N = 1e5 + 100;

int n, t;
double p;
double dp1[2222], dp2[2222];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%lf%d", &n, &p, &t);
    dp1[0] = 1;
    for (int i = 0; i < t; i++) {
        for (int i = 0; i < n; i++) {
            dp2[i + 1] += dp1[i] * p;
            dp2[i] += dp1[i] * (1 - p);
        }
        dp2[n] += dp1[n];
        for (int i = 0; i <= n; i++) {
            dp1[i] = dp2[i];
            dp2[i] = 0;
        }
    }
    double sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += dp1[i] * i;
    }
    printf("%.10lf\n", sum);
    return 0;
}