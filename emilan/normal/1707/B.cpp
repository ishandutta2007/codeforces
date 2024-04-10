#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int zeros = int(count(ALL(a), 0));
    a = vector(begin(a) + zeros, end(a));

    while (SZ(a) > 1) {
        vector<int> tmp;

        if (zeros > 0) {
            tmp.push_back(a[0]);
            zeros--;
        }

        for (int i = 1; i < SZ(a); i++) {
            if (a[i - 1] == a[i]) zeros++;
            else tmp.push_back(a[i] - a[i - 1]);
        }

        sort(ALL(tmp));
        a.swap(tmp);
    }

    if (empty(a)) return 0;
    else return a[0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << solve() << '\n';
    }
}