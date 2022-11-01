#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define all(a) (a).begin(), (a).end()

using ll = long long;

ll pairs(ll n) {
    return n * (n + 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<int>> arr(n);
    vector<int> layer(n);
    vector<int> inside(n);
    vector<int> open_brackets;
    int balance = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            layer[i] = balance;
            arr[layer[i]].push_back(i);
            ++balance;
            open_brackets.push_back(i);
        } else {
            if (balance) {
                --balance;
                open_brackets.pop_back();
                if (balance) {
                    ++inside[open_brackets.back()];
                }
            }
        }
    }
    vector<ll> sum(n);
    sum[0] = pairs(inside[0]);
    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1] + pairs(inside[i]);
    }
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        --l, --r;
        ll res1 = sum[r] - (l ? sum[l - 1] : 0);
        ll res2 = pairs(upper_bound(all(arr[layer[l]]), r) - lower_bound(all(arr[layer[l]]), l));
        cout << res1 + res2 << '\n';
    }
    return 0;
}