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

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

int v[10000];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    int sum1 = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[a]++;
        sum1 += a;
    }

    int sum2 = 0;
    int cur = 0;
    for (int i = 0; i < 10000; i++) {
        cur += v[i];
        if (cur) {
            cur--;
            sum2 += i;
        }
    }

    cout << sum2 - sum1;

    return 0;
}