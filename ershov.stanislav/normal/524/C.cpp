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

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

template <class T>
void mout(T b, T e) {
#ifdef DEBUG
    for (T i = b; i != e; i++) {
        cout << *i << ' ';
    }
    cout << endl;
#endif
}

int a[5555];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif

    int n, k;

    map<int, int> m;

    m[0] = 0;

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        for (int j = 1; j <= k; j++) {
            if (!m.count(j * a[i])) {
                m[j * a[i]] = j;
            } else {
                m[j * a[i]] = min(m[j * a[i]], j);
            }
        }
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);
        int ans = INF;
        for (auto j : m) {
            if (m.count(x - j.fs)) {
                ans = min(ans, m[x - j.fs] + j.sc);
            }
        }
        if (ans > k) {
            printf("-1\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}