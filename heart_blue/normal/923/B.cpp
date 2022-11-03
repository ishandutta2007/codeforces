#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n;
long long v[N], t[N], ts[N];;
long long ans[N], cnt[N];

int main() {
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) cin >> v[i];
        for(int i = 1; i <= n; ++i) cin >> t[i], ts[i] = ts[i - 1] + t[i];
        for(int i = 1; i <= n + 1; ++i) ans[i] = cnt[i] = 0;
        for(int i = 1; i <= n; ++i) {
            int upper = upper_bound(ts + i, ts + 1 + n, v[i] + ts[i - 1]) - ts;
            cnt[i]++; cnt[upper]--;
            ans[upper] += v[i] - (ts[upper - 1] - ts[i - 1]);
            // cout << i << ' ' << upper << ' ' << v[i] - (ts[upper - 1] - ts[i - 1]) << endl;
        }
        for(int i = 1; i <= n; ++i) {
            cnt[i] += cnt[i - 1];
            ans[i] += 1ll * cnt[i] * t[i];
            cout << ans[i] << " \n"[i == n];
        }
    }
    return 0;
}