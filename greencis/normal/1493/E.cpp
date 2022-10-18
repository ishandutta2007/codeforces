#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

string nxt(string s) {
    int carry = 1;
    for (int i = (int)s.size() - 1; carry && i >= 0; --i) {
        carry += s[i] - '0';
        s[i] = '0' + carry % 2;
        carry /= 2;
    }
    if (carry)
        s = "1" + s;
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    string l, r;
    cin >> n >> l >> r;
    if (l[0] != r[0]) {
        for (int i = 0; i < n; ++i)
            l[i] = '1';
        cout << l << endl;
        return 0;
    }
    if (r[n - 1] == '0') {
        if (l == r || nxt(l) == r)
            cout << r << endl;
        else
            cout << nxt(r) << endl;
    } else {
        cout << r << endl;
    }
}