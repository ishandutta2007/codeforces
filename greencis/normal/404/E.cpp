//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> s;
    n = s.size();
    if (s.back() == 'L') {
        for (char& c : s) {
            c ^= 'L' ^ 'R';
        }
    }

    auto check = [&](int x) {
        int cur = 0;
        int mx = 0;
        for (int i = 0; i + 1 < n; ++i) {
            cur += s[i] == 'L' ? -1 : 1;
            if (cur <= -x)
                cur = -x + 1;
            mx = max(mx, cur);
        }
        return cur == mx;
    };

    int L = 0, R = 1.1e6;
    if (check(R)) {
        cout << "1\n";
        return 0;
    }
    while (L < R) {
        int mid = (L + R + 1) >> 1;
        if (check(mid))
            L = mid;
        else
            R = mid - 1;
    }
    cout << L << '\n';
}