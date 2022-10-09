#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int mod = 1e9 + 7;
const int base = 10;

vector<int> calc_hash1(string s) {
    vector<int> ans = {0};
    int now = 1;
    for (auto i : s) {
        ans.push_back((ans.back() + 1ll * now * (i == '(' ? 1 : 2)) % mod);
        now = 1ll * now * base % mod;
    }
    return ans;
}

vector<int> calc_hash2(string s) {
    int n = s.size();
    vector<int> ans(n + 1);
    ans.back() = 0;
    int now = 1;
    for (int i = n - 1; i >= 0; --i) {
        ans[i] = (ans[i + 1] + 1ll * now * (s[i] == '(' ? 1 : 2)) % mod;
        now = 1ll * now * base % mod;
    }
    return ans;
}

int powm(int a, int b) {
    if (b == 0)
        return 1;
    if (b % 2 == 1)
        return 1ll * a * powm(a, b - 1) % mod;
    int z = powm(a, b / 2);
    return 1ll * z * z % mod;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> h = calc_hash1(s);
    vector<int> _h = calc_hash2(s);
    vector<int> t(n + 1);
    t[0] = 1;
    for (int i = 1; i <= n; ++i)
        t[i] = 1ll * t[i - 1] * base % mod;
    int bal = 0;
    int lst = -1, cnt = 0;
    bool bad = false;
    for (int i = 0; i < n; ++i) {
        bal += (s[i] == '(' ? 1 : -1);
        if (bal < 0)
            bad = true;
        int res1 = 1ll * (h[i + 1] - h[lst + 1]) * powm(t[lst + 1], mod - 2) % mod;
        if (res1 < 0)
            res1 += mod;
        int res2 = 1ll * (_h[lst + 1] - _h[i + 1]) * powm(t[n - i - 1], mod - 2) % mod;
        if (res2 < 0)
            res2 += mod;
        if ((!bad && bal == 0) || (res1 == res2 && lst + 1 != i)) {
            lst = i;
            ++cnt;
            bal = 0, bad = false;
        }
    }
    cout << cnt << ' ' << n - lst - 1 << '\n';
}

signed main() {
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif

    SOLVE
    // solve();
}