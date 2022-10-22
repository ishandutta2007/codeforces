#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <chrono>
#include <random>
typedef long long ll;
using namespace std;

const ll mod = 1e9 + 7;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        ll m2 = 1;
        for (int i = 0; i < n - 1; i++) m2 = (m2 << 1) % mod;
        vector<int> l(m), r(m), x(m);
        for (int i = 0; i < m; i++)
        {
            cin >> l[i] >> r[i] >> x[i];
            l[i]--;
            r[i]--;
        }
        ll ans = 0;
        vector<int> no(n + 1, 0);
        for (int i = 0; i < 30; i++)
        {
            fill(no.begin(), no.end(), 0);
            for (int j = 0; j < m; j++)
            {
                if (!(x[j] & (1 << i)))
                {
                    no[l[j]]--;
                    no[r[j] + 1]++;
                }
            }
            bool ok = false;
            for (int j = 0; j < n; j++)
            {
                if (j) no[j] += no[j - 1];
                if (no[j] == 0) ok = true;
            }
            if (ok)
            {
                ans += (m2 * (1ll << i)) % mod;
                ans %= mod;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}