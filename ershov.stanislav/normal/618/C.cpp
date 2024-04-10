#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int maxn = 1e5 + 100;

pair<int, int> ps[maxn];

ll getar(int a, int b, int c) {
    return abs((ll) (ps[b].fs - ps[a].fs) * (ps[c].sc - ps[a].sc) - (ll) (ps[b].sc - ps[a].sc) * (ps[c].fs - ps[a].fs));
}

int a[3] = {0, 1, 2};

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &ps[i].fs, &ps[i].sc);
    }
    for (int i = 2; i < n; i++) {
        if (getar(0, 1, i) != 0) {
            a[2] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == a[0] || i == a[1] || i == a[2]) {
            continue;
        }
        if (getar(a[0], a[1], i) + getar(a[0], a[2], i) + getar(a[1], a[2], i) == getar(a[1], a[2], a[0])) {
          if (getar(a[0], a[1], i)) {
            a[2] = i;
          } else if (getar(a[0], a[2], i)) {
            a[1] = i;
          } else {
            a[0] = i;
          }
        }
    }
    cout << a[0] + 1 << " " << a[1] + 1 << " " << a[2] + 1 << endl;
    return 0;
}