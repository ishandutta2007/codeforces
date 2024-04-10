#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

struct entry {
    ll a, b;
    bool operator<(const entry& rhs) const {
        return b * rhs.a < rhs.b * a;
    }
} e[100105];

int n;
ll p;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> p;
    for (int i = 0; i < n; ++i)
        cin >> e[i].a >> e[i].b;
    sort(e, e + n);

    ld ans = ld(e[0].b) / ld(e[0].a);

    ll suma = 0, sumb = 0;
    for (int i = 0; i < n; ++i) {
        suma += e[i].a;
        sumb += e[i].b;
        ld cur1 = 1e18, cur2 = (i == n - 1 ? 1e18 : ld(e[i + 1].b) / ld(e[i + 1].a));
        if (suma - p > 0)
            cur1 = ld(sumb) / ld(suma - p);
        ans = max(ans, min(cur1, cur2));
        if (cur1 < cur2 && fabs(cur1 - cur2) > 1e-9)
            break;
    }

    if (ans > 1e17)
        cout << -1 << endl;
    else
        cout << setprecision(17) << fixed << ans << endl;

    return 0;
}