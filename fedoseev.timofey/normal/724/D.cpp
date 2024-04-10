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
    int m;
    cin >> m;
    string s;
    cin >> s;
    int n = s.size();
    vector <int> cnt(26);
    vector <int> have(n);
    for (int c = 0; c < 26; ++c) {
        for (int i = 0; i < n; ++i) {
            if (s[i] - 'a' == c) {
                have[i] = 1;
                ++cnt[c];
            }
        }
        bool fl = 1;
        int lst = -1;
        for (int i = 0; i < n; ++i) {
            if (have[i]) {
                fl &= (i - lst - 1 < m);
                lst = i;
            }
        }
        fl &= (n - lst - 1 < m); 
        if (!fl) {
            continue;
        }
        else {
            int lst = -1;
            int nxt = 0;
            for (int i = 0; i < n; ++i) {
                nxt = max(nxt, i + 1);
                while (nxt < n && !have[nxt]) ++nxt;
                if (have[i] && s[i] - 'a' == c && nxt - lst - 1 < m) {
                    --cnt[c];
                }
                else if (have[i]) lst = i;
            }
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < cnt[i]; ++j) {
                    cout << char('a' + i);
                }
            }
            return 0;
        }
    }
}