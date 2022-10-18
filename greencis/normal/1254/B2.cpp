#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[1001001], b[1001001];
ll sum = 0, ans = 1e18;

void check(ll k) {
    copy_n(a, n, b);
    ll need = 0;
    ll s = 0;
    ll sum_left = sum;
    int lastbin = 0;
    int mid = -1;
    for (int i = 0; sum_left > 0; ) {
        if (s == 0 && lastbin == i && mid == -1) {
            ll whole = b[i] / k;
            b[i] = b[i] - whole * k;
            sum_left -= whole * k;
            if (sum_left == 0)
                break;
        }
        if (s + b[i] >= (k + 1) / 2 && mid == -1)
            mid = i;
        if (s + b[i] >= k) {
            ll leftover = s + b[i] - k;
            b[i] -= leftover;
            s = k;
            for (int j = lastbin; j <= i; ++j)
                need += b[j] * (ll)abs(j - mid);

            b[i] = leftover;
            lastbin = i;
            mid = -1;
            sum_left -= k;
            s = 0;
        } else {
            s += b[i];
            ++i;
        }
    }
    ans = min(ans, need);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum <= 1) {
        cout << -1 << endl;
        return 0;
    }

    ll x = sum;
    for (ll i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            check(i);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
        check(x);
    cout << ans << endl;
}