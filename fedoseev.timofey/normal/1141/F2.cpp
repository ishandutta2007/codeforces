#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector <vector <pair <int, int>>> kek;

int get(int id) {
    int r = -1;
    int res = 0;
    for (auto p : kek[id]) {
        if (p.first > r) {
            ++res;
            r = p.second;
        }
    }
    return res;
}

void get_ans(int id) {
    int r = -1;
    for (auto p : kek[id]) {
        if (p.first > r) {
            cout << p.first + 1 << ' ' << p.second + 1 << '\n';
            r = p.second;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> pref(n + 1);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
    vector <pair <int, int>> seg;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            seg.emplace_back(i, j);
        }
    }
    auto sum = [&] (pair <int, int> a) {
        return pref[a.second + 1] - pref[a.first];
    };
    sort(seg.begin(), seg.end(), [&] (pair <int, int> f, pair <int, int> s) {
        return sum(f) < sum(s);
    });
    for (int i = 0; i < (int)seg.size(); ++i) {
        if (i == 0 || sum(seg[i]) != sum(seg[i - 1])) {
            kek.push_back({});
        }
        kek.back().push_back(seg[i]);
    }
    for (int i = 0; i < (int)kek.size(); ++i) {
        sort(kek[i].begin(), kek[i].end(), [&] (pair <int, int> f, pair <int, int> s) {
            return f.second < s.second;
        });
    }
    int ans = 0, who = -1;
    for (int i = 0; i < (int)kek.size(); ++i) {
        int cur = get(i);
        if (cur > ans) {
            ans = cur;
            who = i;
        }
    }
    cout << ans << '\n';
    get_ans(who);
}