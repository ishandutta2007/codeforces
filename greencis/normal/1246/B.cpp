#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


int main() {
    ios_base::sync_with_stdio(false);

    map<vector<pii>, int> counter;
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        vector<pii> v, vr;
        for (int j = 2; j * j <= x; ++j) {
            int cnt = 0;
            while (x % j == 0) {
                ++cnt;
                x /= j;
            }
            cnt %= k;
            if (cnt)
                v.emplace_back(j, cnt);
        }
        if (x > 1)
            v.emplace_back(x, 1);
        vr = v;
        for (auto& p : vr)
            p.second = (k - p.second) % k;
        ans += counter[vr];
        ++counter[v];
    }
    cout << ans << endl;
}