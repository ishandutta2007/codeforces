#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int maxn = 200010;
const long long P = 10000000000001657;
int n, num[maxn][26];
long long pre[maxn], suf[maxn], pw[maxn], hv[26][maxn];
string s[maxn];
pair<string, long long> a[maxn];
long long ans;
vector<int> nxt[maxn];
__gnu_pbds::gp_hash_table<long long, int> cnt;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        string t = a[i].first;
        sort(t.begin(), t.end());
        for (char c : t) a[i].second = (26 * a[i].second + c - 'a') % P;
    }
    sort(a + 1, a + n + 1, [&](pair<string, long long> a, pair<string, long long> b)
        { return a.second < b.second; });
    int len = a[1].first.size();
    for (int i = 1; i <= n; i++) {
        s[i] = a[i].first, nxt[i].resize(len);
        for (int j = len - 1; ~j; j--) {
            if (j + 1 < len && s[i][j] <= s[i][j + 1]) nxt[i][j] = nxt[i][j + 1];
            else nxt[i][j] = j;
        }
    }
    for (int i = pw[0] = 1; i <= len; i++) {
        pw[i] = 26 * pw[i - 1] % P;
    }
    for (int c = 0; c < 26; c++) {
        for (int i = 1; i <= len; i++) {
            hv[c][i] = (26 * hv[c][i - 1] + c) % P;
        }
    }
    auto solve = [&](int l, int r) {
        if (n <= 10000) {
            for (int i = l; i <= r; i++) {
                for (int j = i + 1; j <= r; j++) {
                    int p = 0, q = len - 1;
                    while (s[i][p] == s[j][p]) p++;
                    while (s[i][q] == s[j][q]) q--;
                    if (nxt[i][p] >= q || nxt[j][p] >= q) ans++;
                    else ans += 2;
                }
            }
        } else {
            ans += 1LL * (r - l) * (r - l + 1), cnt.clear();
            auto calc = [&](int i) {
                for (int j = 0; j < len; j++) {
                    pre[j] = (26 * (j ? pre[j - 1] : 0) + s[i][j] - 'a') % P;
                    for (int k = 0; k < 26; k++) {
                        num[j][k] = (j ? num[j - 1][k] : 0) + (s[i][j] == k + 'a');
                    }
                }
                for (int j = len - 1; ~j; j--) {
                    suf[j] = (pw[len - j - 1] * (s[i][j] - 'a') + suf[j + 1]) % P;
                }
                ans -= cnt[pre[len - 1]];
                vector<long long> V;
                for (int j = 0; j < len; j++) {
                    for (int k = j; k < len; k++) {
                        long long h = j ? pre[j - 1] : 0;
                        for (int l = 0; l < 26; l++) {
                            int t = num[k][l] - (j ? num[j - 1][l] : 0);
                            h = (h * pw[t] + hv[l][t]) % P;
                        }
                        h = (h * pw[len - k - 1] + suf[k + 1]) % P;
                        V.push_back(h);
                    }
                }
                sort(V.begin(), V.end());
                V.resize(unique(V.begin(), V.end()) - V.begin());
                for (long long h : V) cnt[h]++;
            };
            for (int i = l; i <= r; i++) calc(i);
            cnt.clear();
            for (int i = r; i >= l; i--) calc(i);
        }
    };
    for (int i = 1, j; i <= n; i = j) {
        for (j = i; j <= n && a[i].second == a[j].second; j++);
        solve(i, j - 1);
        ans += 1337LL * (i - 1) * (j - i);
    }
    cout << ans << '\n';
    return 0;
}