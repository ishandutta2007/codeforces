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

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    int n, k;

    cin >> n >> k;

    if (k > (n * n + 1) / 2) {
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0 && k) {
                k--;
                cout << "L";
            } else {
                cout << "S";
            }
        }
        cout << endl;
    }

    return 0;
}