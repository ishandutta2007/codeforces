#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

map <char, pair <int, int>> d;

pair <int, int> operator+(const pair <int, int> &a, const pair <int, int> &b) {
    pair <int, int> c = a;
    c.first += b.first;
    c.second += b.second;
    return c;
}

bool check(pair <int, int> a, int x, int y, int c) {
    int f = x - a.first;
    int s = y - a.second;
    if (abs(f) + abs(s) <= c && abs(f + s) % 2 == c % 2) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    d['U'] = {0, 1};
    d['D'] = {0, -1};
    d['L'] = {-1, 0};
    d['R'] = {1, 0};
    int n;
    cin >> n;
    vector <pair <int, int>> pref(n + 1);
    vector <pair <int, int>> suf(n + 1);
    vector <pair <int, int>> a(n);
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        a[i] = d[c];
    }
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = suf[i + 1] + a[i];
    }
    if (check(pref[n], x, y, 0)) {
        cout << 0 << '\n';
        return 0;
    }
    int ans = 1e9;
    int r = 0;
    for (int l = 0; l < n; ++l) {
        while (r < n && !check(pref[l] + suf[r + 1], x, y, r - l + 1)) {
            ++r;
        }
        if (r != n) ans = min(ans, r - l + 1);
    }
    if (ans > 1e8) {
        cout << -1 << '\n';
    }
    else {
        cout << ans << '\n';
    }
}