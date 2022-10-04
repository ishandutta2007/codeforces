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
    vector <pair <int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [&] (pair <int, int> f, pair <int, int> s) {
        if (f.first != s.first) return f.first < s.first;
        return f.second < s.second;
    });
    int lst = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i].second >= lst) lst = a[i].second;
        else lst = a[i].first;
    }
    cout << lst << '\n';
}