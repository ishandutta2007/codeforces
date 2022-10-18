#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    string s;
    cin >> n >> p >> s;
    int i = n - 1;
    for (; i >= 0; --i) {
        bool good = false;
        for (int j = 0; j < 3; ++j) {
            if (++s[i] >= 'a' + p) break;
            if ((i < 1 || s[i - 1] != s[i]) && (i < 2 || s[i - 2] != s[i])) {
                good = true;
                break;
            }
        }
        if (good)
            break;
    }
    if (i == -1) {
        cout << "NO\n";
    } else {
        for (++i; i < n; ++i) {
            for (int j = 0; j < p && j < 3; ++j) {
                s[i] = 'a' + j;
                if ((i < 1 || s[i - 1] != s[i]) && (i < 2 || s[i - 2] != s[i])) {
                    break;
                }
            }
        }
        cout << s << '\n';
    }
}