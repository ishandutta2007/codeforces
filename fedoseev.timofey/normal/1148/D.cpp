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
    vector <int> fa, fb, sa, sb;
    vector <int> fi, si;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (a < b) {
            fa.push_back(a);
            fb.push_back(b);
            fi.push_back(i);
        }
        else {
            sa.push_back(b);
            sb.push_back(a);
            si.push_back(i);
        }
    }
    vector <int> res;

    auto solve = [&] (vector <int> a, vector <int> b, vector <int> idx, bool fl) {
        int m = a.size();
        vector <int> id(m);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&] (int i, int j) {
            return b[i] > b[j];
        });

        vector <int> cur;
        int lst = 1e9;
        for (int i : id) {
            if (a[i] < lst) {
                cur.push_back(idx[i]);
                lst = b[i];
            }
        }
        if (fl) reverse(cur.begin(), cur.end());
        if (cur.size() > res.size()) res = cur;
    };
    solve(fa, fb, fi, 0);
    solve(sa, sb, si, 1);
    cout << res.size() << '\n';
    for (auto i : res) {
        cout << i + 1 << ' ';
    }
}