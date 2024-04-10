#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

struct mymap {
    vector<long long> who;
    vector<int> val;
    const int inf = 1e9 + 228;

    const int a = 321412;

    int& operator[](long long ind) {
        int c = (1ll * a * ind) % who.size();
        while (who[c] != inf && who[c] != ind) {
            ++c;
            if (c == who.size())
                c = 0;
        }
        who[c] = ind;
        return val[c];
    }

    mymap(int n) {
        who.resize(n, inf);
        val.resize(n);
    }
};

bool check(int a) {
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0)
            return false;
    }
    return true;
}

int prime(int pos) {
    while (!check(pos))
        ++pos;
    return pos;
}

signed main() {
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    vector<int> a(n);
    const int C = 333;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = -C; i <= C; ++i) {
        mymap cnt(prime(2 * n));
        // unordered_map<long long, int> cnt(2 * n);
        for (int j = 0; j < n; ++j)
            cnt[a[j] - 1ll * i * j]++;
        for (auto i : cnt.val)
            ans = max(ans, i);
        // for (auto i : cnt)
        //     ans = max(ans, i.second);  
    }
    for (int i = 0; i < n; ++i) {
        // unordered_map<long long, int> res(4 * C);
        mymap res(prime(4 * C));
        for (int k = 1; k <= C; ++k) {
            if (i + k < n) {
                if ((a[i + k] - a[i]) % k == 0)
                    res[(a[i + k] - a[i]) / k]++;
            }
            if (i - k >= 0) {
                if ((a[i] - a[i - k]) % k == 0)
                    res[(a[i] - a[i - k]) / k]++;
            }
        }
        for (auto i : res.val)
            ans = max(ans, i + 1);
        // for (auto i : res)
        //     ans = max(ans, i.second + 1);
    }
    cout << n - ans << '\n';
}