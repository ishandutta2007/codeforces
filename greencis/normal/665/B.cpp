#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

int n, m, k, x;
vector<int> p;
ll ans;

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        cin >> x;
        p.push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> x;
            int idx = -1;
            for (int z = 0; z < k; ++z) {
                if (p[z] == x) {
                    idx = z;
                    break;
                }
            }
            ans += idx + 1;
            p.erase(p.begin() + idx);
            p.insert(p.begin(), x);
        }
    }

    cout << ans;

    return 0;
}