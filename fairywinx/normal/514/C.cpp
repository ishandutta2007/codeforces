#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

#define int long long
 
using namespace std;

const int mod = 1337133713371337;
const int base = 228;
const int N = 6e5 + 228;
int pw[N];

int h(string s) {
    int pw = 1;
    int ans = 0;
    for (int i : s) {
        ans = (ans + 1ll * pw * i) % mod;
        pw = 1ll * pw * base % mod;
    }
    return ans;
}

signed main() {
    #ifdef DEBUG
        freopen( "main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n, m;
    cin >> n >> m;
    set<int> tmp;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        tmp.insert(h(s));
    }
    pw[0] = 1;
    for (int i = 1; i < N; ++i) {
        pw[i] = 1ll * base * pw[i - 1] % mod;
    }
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        int res = h(s);
        bool find = false;
        for (int j = 0; j < (int) s.size(); ++j) {
            for (int k = 'a'; k <= 'c'; ++k) {
                if (k == s[j])
                    continue;
                long long z = res - 1ll * pw[j] * s[j] + 1ll * pw[j] * k;
                z = (z % mod + mod) % mod;
                if (tmp.count(z)) {
                    find = true;
                }
            }
        }
        if (find) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}