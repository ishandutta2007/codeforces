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
    vector <int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    vector <pair <int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        int X = x[0] + a[i].first;
        int Y = y[0] + a[i].second;
        vector <pair <int, int>> need;
        for (int j = 0; j < n; ++j) {
            need.push_back({X - x[j], Y - y[j]});
        }
        sort(need.begin(), need.end());
        if (need == a) {
            cout << X << ' ' << Y << '\n';
            return 0;
        }
    }
}