//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(all(v));
    vector<ll> ans(n, 0);
    ll sum = 0;
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (i % m == 0) {
            sum += v[i];
            ++cnt;
        }
        ans[i] += v[i] * cnt - sum;
    }
    sum = 0;
    cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (i % m == 0) {
            sum += v[n - 1 - i];
            ++cnt;
        }
        ans[n - i - 1] += sum - v[n - i - 1] * cnt;
    }
    ll res = 2 * *min_element(all(ans));
    cout << res << endl;
}