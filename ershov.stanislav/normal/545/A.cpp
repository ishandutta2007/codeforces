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

const int N = 111;

bool bad[N];

int n;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            if (a == 1) {
                bad[i] = true;
            } else if (a == 2) {
                bad[j] = true;
            } else if (a == 3) {
                bad[i] = bad[j] = true;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!bad[i]) {
            cnt++;
        }
    }
    cout << cnt << endl;
    for (int i = 1; i <= n; i++) {
        if (!bad[i]) {
            cout << i << ' ';
        }
    }
    return 0;
}