#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 100005;
int a[maxn], p[maxn], h[maxn], w[maxn];
array<int, 3> q[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, s; cin >> n >> m; s = sqrt(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++) {
        cin >> q[i][0] >> q[i][1]; q[i][1]--;
        if (q[i][0] == 0) cin >> q[i][2];
    }

    for (int j = 0; j < m; j += s) {

        for (int i = j; i < min(j+s, m); i++)
            if (q[i][0] == 0)
                h[q[i][1]] = 1;

        for (int i = n-1; i >= 0; i--) {
            if ((!h[i]) && (!h[i+a[i]]) && i+a[i]+a[i+a[i]] < n) {
                p[i] = a[i]+p[i+a[i]];
                w[i] = w[i+a[i]]+1;
            } else {
                p[i] = a[i];
                w[i] = 1;
            }
        }

        for (int i = j; i < min(j+s, m); i++) {
            auto& [t, x, y] = q[i];
            if (t == 0) {
                h[x] = 0;
                a[x] = p[x] = y;
            } else {
                int r = 0;
                for (; x+p[x] < n; x += p[x])
                    r += w[x];
                cout << x+1 << " " << r+1 << "\n";
            }
        }
    }
}