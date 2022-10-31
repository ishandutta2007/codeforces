#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fs first
#define sc second
#define mp make_pair

#define next _next
#define prev _prev
#define hash _hash
#define all(s) s.begin(), s.end()

#ifdef DEBUG
#define dout(x) cerr << x
#else
#define dout(x)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 2 * 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#define PROBLEM "B"

template <class T>
void mout(T b, T e) {
#ifdef DEBUG
    for (T i = b; i != e; i++) {
        cout << *i << ' ';
    }
    cout << endl;
#endif
}

const int N = 1050;

int w[N], h[N];

int main()
{
#ifdef DEBUG
    assert(freopen(PROBLEM".in", "r", stdin) != NULL);
#else
//  assert(freopen(PROBLEM".in", "r", stdin) != NULL);
//  assert(freopen(PROBLEM".out", "w", stdout));
#endif

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &w[i], &h[i]);
        if (w[i] > h[i]) {
            swap(w[i], h[i]);
        }
    }
    int ans = INF;
    for (int y = 1; y <= 1000; ++y) {
        int len = 0;
        for (int i = 0; i < n; ++i) {
            if (h[i] <= y) {
                len += w[i];
            }
            else if (w[i] > y) {
                len = INF;
                break;
            }
            else {
                len += h[i];
            }
        }
        if (len == INF) continue;
        ans = min(ans, len * y);
    }
    cout << ans << endl;
    return 0;
}