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

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

int cnt[400];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    int k;
    cin >> k;
    if (k % 2 == 0) {
        cout << "NO" << endl;
    } else if (k != 1) {
        int n = (k + 2) * 2;
        cout << "YES" << endl;
        vector<pair<int, int> > e;
        for (int i = 0; i < k + 1; i++) {
            for (int j = i + 1; j < k + 1; j++) {
                if (j != i + 1 || i == k - 1 || i % 2 != 0) {
                    e.eb(i, j);
                }
            }
        }
        for (int i = 0; i < k + 1; i++) {
            for (int j = i + 1; j < k + 1; j++) {
                if (j != i + 1 || i == k - 1 || i % 2 != 0) {
                    e.eb(i + k + 3, j + k + 3);
                }
            }
        }
        for (int i = 0; i < k - 1; i++) {
            e.eb(i, k + 1);
        }
        for (int i = k + 3; i < n - 2; i++) {
            e.eb(i, k + 2);
        }
        e.eb(k + 1, k + 2);
        cout << n << ' ' << e.size() << endl;
        for (auto i : e) {
            cout << i.fs + 1 << ' ' << i.sc + 1 << endl;
            cnt[i.fs]++;
            cnt[i.sc]++;
        }
    } else if (k == 1) {
        cout << "YES\n2 1\n1 2\n";
    }
    return 0;
}