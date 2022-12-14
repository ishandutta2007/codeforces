#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

const int maxm = 4e5;
int cnt[maxm];

void solve() {
    int a;
    string s;
    cin >> a >> s;
    int n = sz(s);

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += s[j] - '0';
            cnt[sum]++;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += s[j] - '0';

            if (!a) {
                if (!sum) ans += n * (n + 1) / 2;
                else ans += cnt[0];
            } else if (sum && !(a % sum) && a / sum < maxm) {
                ans += cnt[a / sum];
            }
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}