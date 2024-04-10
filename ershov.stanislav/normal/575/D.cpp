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
#define rank _rank

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

const int N = 7e5 + 100;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cout << 2000 << endl;
    for (int i = 1; i <= 1000; i++) {
        cout << i << ' ' << 1 << ' ' << i << ' ' << 2 << endl;
    }
    for (int i = 1000; i >= 1; i--) {
        cout << i << ' ' << 1 << ' ' << i << ' ' << 2 << endl;
    }
    return 0;
}