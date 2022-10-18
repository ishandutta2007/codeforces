#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

struct Entry {
    int pos;
    int like;
    int idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        vector<Entry> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i].pos;
        }
        string s;
        cin >> s;
        for (int i = 0; i < n; ++i) {
            v[i].like = s[i] - '0';
            v[i].idx = i;
        }
        sort(all(v), [](const Entry& a, const Entry& b) {
            if (a.like != b.like)
                return a.like < b.like;
            return a.pos < b.pos;
        });
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
            ans[v[i].idx] = i + 1;
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}