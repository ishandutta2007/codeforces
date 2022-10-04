#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <ll> ans;
    for (int d = 1; d * d <= n; ++d) {
        if ((n % d) == 0) {
            int cur = ((-d + n) % n) + 1;
            ans.push_back((ll)(1 + cur) * (n / d) / 2);
            cur = ((-(n / d) + n) % n) + 1;
            ans.push_back((ll)(1 + cur) * d / 2);
        }
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    for (auto x : ans) {
        cout << x << ' ';
    }
}