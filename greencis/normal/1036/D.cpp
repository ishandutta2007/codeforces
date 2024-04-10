#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m;
ll a[300105], b[300105];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; ++i) cin >> b[i];
    int ai = 0, bi = 0;
    int cnt = 0;
    while (ai < n && bi < m) {
        ll as = 0, bs = 0;
        do {
            if (ai == n || (bi < m && bs < as))
                bs += b[bi++];
            else
                as += a[ai++];
        } while (as != bs && (ai < n || bi < m));
        if (as != bs) { ai = bi = 0; break; }
        ++cnt;
    }
    if (ai != n || bi != m)
        cout << -1 << endl;
    else
        cout << cnt << endl;
}