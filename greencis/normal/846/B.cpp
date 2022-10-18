#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, k, m, all, ans, a[55];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> k >> m;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        all += a[i];
    }
    sort(a, a + k);
    for (int i = 0; i <= n; ++i) {
        if (all * i > m) continue;
        int tm = m - all * i;
        int curans = i * (k + 1);
        vector<int> v;
        for (int z = 0; z < k; ++z)
            for (int j = 0; j < n - i; ++j)
                v.push_back(a[z]);
        int idx = 0;
        while (idx < v.size() && tm - v[idx] >= 0) {
            ++curans;
            tm -= v[idx];
            ++idx;
        }
        ans = max(ans, curans);
    }
    cout << ans << endl;

    return 0;
}