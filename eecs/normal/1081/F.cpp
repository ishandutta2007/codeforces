#include <bits/stdc++.h>
using namespace std;

const int maxn = 310;
int n, T;

int main() {
    cin >> n >> T;
    auto ask = [&](int l, int r) {
        cout << "? " << l << " " << r << endl;
        int x; cin >> x; return x;
    };
    auto flip = [&](int l, int r, int t, int R = 1, int L = 0) {
        int gl = 0, gr = 0;
        while (1) {
            int t1 = ask(l, r);
            if (((t - t1) & 1) == (r & 1)) gr ^= 1;
            else gl ^= 1;
            t = t1;
            if (gl == L && gr == R) return t;
        }
    };
    if (n == 1) {
        cout << "! " << T << endl;
    } else if (n & 1) {
        vector<char> s(n + 1);
        for (int i = 1, lst = 0; i < n; i++) {
            int t = flip(i, i + 1, T), x = (T + i + 1 - t) >> 1;
            if (i > 1) s[i + 1] = '0' + x - lst;
            lst = x, flip(i, i + 1, t);
        }
        int t = flip(2, n, T, 0, 1), x = (T + n - 1 - t) >> 1;
        for (int i = 3; i <= n; i++) if (s[i] == '1') x--;
        s[2] = x + '0';
        for (int i = 2; i <= n; i++) if (s[i] == '1') T--;
        s[1] = T + '0';
        cout << "! ";
        for (int i = 1; i <= n; i++) cout << s[i];
        cout << endl;
    } else {
        string s;
        for (int i = 1, lst = 0; i <= n; i++) {
            int t = flip(i, i, T), x = (T + i - t) >> 1;
            s.push_back('0' + x - lst);
            lst = x, flip(i, i, t);
        }
        cout << "! " << s << endl;
    }
    return 0;
}