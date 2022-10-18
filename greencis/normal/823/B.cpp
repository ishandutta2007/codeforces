#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const string ACGT = "ACGT";
vector<int> t[4][11][11];

inline void update(int z, int len, int start, int idx, int val) {
    for (; idx < t[z][len][start].size(); idx |= idx + 1)
        t[z][len][start][idx] += val;
}

inline void update(int z, int len, int idx, int val) {
    int real_idx = idx / len;
    int start = idx % len;
    update(z, len, start, real_idx, val);
}

inline int get(int z, int len, int start, int idx) {
    if (idx < 0)
        return 0;
    int real_idx = idx / len;
    if (start <= idx % len)
        ++real_idx;
    --real_idx;
    int ans = 0;
    for (; real_idx >= 0; real_idx = (real_idx & (real_idx + 1)) - 1)
        ans += t[z][len][start][real_idx];
    return ans;
}

char bits[4][100005];

int main()
{
    ios_base::sync_with_stdio(false);

    for (int z = 0; z < 4; ++z)
        for (int len = 1; len <= 10; ++len)
            for (int start = 0; start < len; ++start)
                t[z][len][start].resize((100000 + len - 1) / len + 5);

    string s;
    cin >> s;
    for (int z = 0; z < 4; ++z) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ACGT[z]) {
                bits[z][i] = 1;
                for (int len = 1; len <= 10; ++len)
                    update(z, len, i, 1);
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int tp, x, y;
        cin >> tp >> x;
        --x;
        if (tp == 1) {
            char c;
            cin >> c;
            for (int z = 0; z < 4; ++z) {
                if (ACGT[z] == c) {
                    for (int zz = 0; zz < 4; ++zz)
                        if (ACGT[zz] == s[x]) {
                            for (int len = 1; len <= 10; ++len)
                                update(zz, len, x, -1);
                            bits[zz][x] = 0;
                            break;
                        }
                    bits[z][x] = 1;
                    for (int len = 1; len <= 10; ++len)
                        update(z, len, x, 1);
                    s[x] = c;
                    break;
                }
            }
        } else {
            string pattern;
            cin >> y >> pattern;
            --y;
            if (pattern.size() >= y - x + 1)
                pattern = pattern.substr(0, y - x + 1);
            pattern = pattern.substr(pattern.size() - x % pattern.size(), x % pattern.size()) + pattern.substr(0, pattern.size() - x % pattern.size());
            int ans = 0;
            for (int z = 0; z < 4; ++z) {
                for (int i = 0; i < pattern.size(); ++i) {
                    if (pattern[i] == ACGT[z]) {
                        ans += get(z, pattern.size(), i, y) - get(z, pattern.size(), i, x - 1);
                    }
                }
            }
            cout << ans << "\n";
        }
    }

    return 0;
}