#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int K = 62;

vector <int> who[K];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> val(n);
    vector <ll> mask(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> val[i] >> mask[i];
        sum += val[i];
        for (int j = 0; j < K; ++j) {
            if (mask[i] & (1LL << j)) {
                who[j].push_back(i);
                break;
            }
        }
    }
    if (sum < 0) {
        for (int i = 0; i < n; ++i) {
            val[i] *= -1;
        }
        sum *= -1;
    }
    ll ans = 0;
    for (int i = K - 1; i >= 0; --i) {
        ll cs = 0;
        for (int j : who[i]) {
            cs += val[j];
        }
        if (cs > 0) {
            ans |= (1LL << i);
            for (int j = 0; j < n; ++j) {
                if (mask[j] & (1LL << i)) {
                    val[j] *= -1;
                }
            }   
        }
    }
    cout << ans << '\n';
}