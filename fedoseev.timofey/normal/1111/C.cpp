#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n, k, a, b;
vector <int> p;

ll solve(int l, int r) {
    int cnt = lower_bound(p.begin(), p.end(), r) - lower_bound(p.begin(), p.end(), l);
    if (cnt == 0) return a;
    if (l + 1 == r) {
        return (ll)(r - l) * b * cnt;
    }
    int m = (l + r) >> 1;
    return min((ll)(r - l) * b * cnt, solve(l, m) + solve(m, r));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> k >> a >> b;
    p.resize(k);
    for (int i = 0; i < k; ++i) {
        cin >> p[i];
        --p[i];
    }
    sort(p.begin(), p.end());
    cout << solve(0, 1 << n);
}