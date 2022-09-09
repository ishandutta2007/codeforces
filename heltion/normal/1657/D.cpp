#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    LL C;
    cin >> n >> C;
    vector<LL> c(n), d(n), h(n);
    vector<LL> dh(C + 1);
    for (int i = 0; i < n; i += 1) {
        cin >> c[i] >> d[i] >> h[i];
        dh[c[i]] = max(dh[c[i]], d[i] * h[i]);
    }
    for (int i = 1; i <= C; i += 1) {
        dh[i] = max(dh[i - 1], dh[i]);
        for (int j = i; j <= C; j += i)
            dh[j] = max(dh[j], dh[i] * j / i);
    }
    //for (int i = 1; i <= C; i += 1) cout << i << " " << dh[i] << "\n";
    int m;
    cin >> m;
    vector<LL> D(m), H(m);
    //min(kc : HD < kdh)
    for (int i = 0; i < m; i += 1) {
        cin >> D[i] >> H[i];
        int res = upper_bound(dh.begin(), dh.end(), D[i] * H[i]) - dh.begin();
        cout << (res > C ? -1 : res) << "\n";
    }
    return 0;
}