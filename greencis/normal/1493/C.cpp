#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        if (n % k) {
            cout << "-1\n";
            continue;
        }
        vector<int> cnt(26);
        for (char c : s)
            ++cnt[c - 'a'];
        bool good = true;
        for (int i = 0; i < 26; ++i)
            good &= cnt[i] % k == 0;
        if (good) {
            cout << s << '\n';
            continue;
        }
        for (int i = n - 1; !good && i >= 0; --i) {
            --cnt[s[i] - 'a'];
            for (char c = s[i] + 1; !good && c <= 'z'; ++c) {
                s[i] = c;
                ++cnt[c - 'a'];
                int must = 0;
                for (int z = 0; z < 26; ++z) {
                    int cur = cnt[z] % k;
                    if (cur != 0)
                        must += k - cur;
                }
                if (must <= n - i - 1) {
                    good = true;
                    int ptr = i + 1;
                    for (int z = 0; z < 26; ++z) {
                        int cur = cnt[z] % k;
                        if (cur != 0)
                            cur = k - cur;
                        if (z == 0)
                            cur += (n - i - 1) - must;
                        while (cur--)
                            s[ptr++] = 'a' + z;
                    }
                    break;
                }
                --cnt[c - 'a'];
            }
        }
        cout << s << '\n';
    }
}