#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector <int> p, pos;
vector <pair <int, int>> ans;

int n;

void sw(int a, int b) {
    if (a == b) return;
    if (a > b) swap(a, b);
    if (2 * abs(a - b) >= n) {
        ans.emplace_back(a + 1, b + 1);
        swap(pos[p[a]], pos[p[b]]);
        swap(p[a], p[b]);
    }
    else {
        if (a < n / 2 && b < n / 2) {
            sw(a, n - 1);
            sw(b, n - 1);
            sw(a, n - 1);
        }
        else if (a >= n / 2 && b >= n / 2) {
            sw(a, 0);
            sw(b, 0);
            sw(a, 0);
        }
        else {
            sw(a, n - 1);
            sw(b, n - 1);
            sw(a, n - 1);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; ++i) cin >> p[i], --p[i];
    pos.resize(n);
    for (int i = 0; i < n; ++i) pos[p[i]] = i;
    for (int i = 0; i < n; ++i) {
        int x = pos[i];
        sw(i, pos[i]);
    }
    assert(is_sorted(p.begin(), p.end()));
    cout << ans.size() << '\n';
    for (auto pr : ans) {
        cout << pr.first << ' ' << pr.second << '\n';
    }
}