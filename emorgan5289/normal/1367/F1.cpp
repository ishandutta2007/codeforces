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

const int maxn = 200005;
int a[maxn], p[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        iota(p, p+n, 0);
        sort(p, p+n, [&](int i, int j) {
            return a[i] == a[j] ? i < j : a[i] < a[j];
        });
        int out = 0, x = 0;
        for (int i = 1; i <= n; i++) {
            if (i == n || p[i] <= p[i-1]) {
                int k = i-x;
                for (int j = i; j < n && a[p[j]] == a[p[i]]; j++)
                    if (p[j] > p[i-1]) k++;
                for (int j = x-1; j >= 0 && a[p[j]] == a[p[x-1]]; j--)
                    if (p[j] < p[x]) k++;
                out = max(out, k);
                x = i;
            }
        }

        // this is all for an edge case
        map<int, int> l, r;
        for (int i = 0; i < n; i++) {
            r[a[i]]++; out = max(out, r[a[i]]);
        }
        for (int i = 0; i < n; i++) {
            r[a[i]]--; l[a[i]]++;
            auto ur = r.upper_bound(a[i]), ul = l.upper_bound(a[i]);
            int k = min(ur == r.end() ? inf+1 : ur->first, ul == l.end() ? inf+1 : ul->first);
            if (k != inf+1) {
                debug(i, k, l[a[i]], r[k]);
                out = max(out, l[a[i]]+r[k]);
            }
        }

        cout << n-out << "\n";
    }
}