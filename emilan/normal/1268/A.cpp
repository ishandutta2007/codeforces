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

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string fi = s.substr(0, k);
    for (int i = k; i < n; i += k) {
        string cmp(s.substr(i, min(k, n - i)));

        if (fi != cmp) {
            if (fi < cmp) {
                fi.back()++;
                for (int j = k - 1; fi[j] > '9'; j--) {
                    fi[j] = '0';
                    fi[j - 1]++;
                }
            }
            break;
        }
    }

    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << fi[i % k];
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}