#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

#define long long

const int N = 1e6 + 228;
const long double eps = 1e-8;

int cnt[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    reverse(all(s1));
    reverse(all(s2));

    for (int i = 0; i < (int) s1.size(); ++i) {
        if (s1[i] == '1')
            ++cnt[i];
    }
    for (int i = 0; i < (int) s2.size(); ++i)
        if (s2[i] == '1')
            --cnt[i];

    for (int i = N - 2; i >= 2; --i) {
        if (cnt[i] >= 2) {
            cout << ">\n";
            return 0;
        } else if (cnt[i] <= -2) {
            cout << "<\n";
            return 0;
        }
        cnt[i - 1] += cnt[i];
        cnt[i - 2] += cnt[i];
        cnt[i] = 0;
    }

    const long double q = (sqrt(5) + 1) / 2;
    long double x = (cnt[0] * 1) + (long double) (cnt[1] * q);
    if (abs(x) < eps) {
        cout << "=\n";
        return 0;
    }
    if (x < eps) {
        cout << "<\n";
    }
    else {
        cout << ">\n";
    }
}