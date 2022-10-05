# include <iostream>
# include <vector>

using namespace std;

const int Maxn = 123456;
const int Inf = 1e9 + 7;

int min_pref[Maxn];
int max_pref[Maxn];
int min_suff[Maxn];
int max_suff[Maxn];
int a[Maxn];

int main() {
    long long n, p, q, r;
    cin >> n >> p >> q >> r;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        min_pref[i] = min_suff[i] = Inf;
        max_pref[i] = max_suff[i] = -Inf;
    }
    min_pref[0] = max_pref[0] = a[0];
    max_suff[n - 1] = min_suff[n - 1] = a[n - 1];
    for (int i = 1; i < n; ++i) {
        min_pref[i] = min(min_pref[i - 1], a[i]);
        max_pref[i] = max(max_pref[i - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        min_suff[i] = min(min_suff[i + 1], a[i]);
        max_suff[i] = max(max_suff[i + 1], a[i]);
    }
    long long ans = -3e18;
    for (int i = 0; i < n; ++i) {
        long long cur = 0;
        cur += q * a[i];
        if (p < 0) cur += min_pref[i] * p;
        else cur += max_pref[i] * p;
        if (r < 0) cur += min_suff[i] * r;
        else cur += max_suff[i] * r;
        ans = max(ans, cur);
    }
    cout << ans << endl;
}