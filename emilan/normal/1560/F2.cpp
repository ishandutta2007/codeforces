#include <bits/stdc++.h>

using namespace std;

string solve() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();

    vector<int> f(11);
    f[10] = 1;
    for (int i = 0; i < n; i++) {
        f[ s[i] - '0' ]++;
    }

    auto inc = [&](int i) {
        f[s[i] - '0']--;
        s[i]++;
        f[s[i] - '0']++;
    };

    auto ugly = [&]() {
        return 10 - count(f.begin(), f.end(), 0);
    };

    if (ugly() <= k) return s;
    for (int i = n - 1; i >= 0; i--) {
        for (inc(i); s[i] <= '9'; inc(i)) {
            if (ugly() <= k) {
                int x = 0;
                if (ugly() == k) {
                    for (; f[x] == 0; x++);
                }

                for (int j = i + 1; j < n; j++) {
                    s[j] = x + '0';
                }

                return s;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << solve() << "\n";
    }
}