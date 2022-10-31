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

using namespace std;

const int N = 200200;

int n, t, m;
double c;
ll a[N];
double approx[N];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d%d%lf", &n, &t, &c);

//    cerr << c;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        approx[i] = (approx[i - 1] + a[i] * 1.0 / t) / c;
    }
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int p;
        scanf("%d", &p);
        double real = (double) (a[p] - a[p - t]) / t;
        printf("%.10lf %.10lf %.10lf\n", real, approx[p], abs(real - approx[p]) / real);
    }
    return 0;
}