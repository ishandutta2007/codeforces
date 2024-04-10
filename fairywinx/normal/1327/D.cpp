#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

bool check(vector<int> &a, int n, int k) {
    vector<int> res(k, -1);
    for (int i = 0; i < n; ++i) {
        if (res[i % k] == -1) {
            res[i % k] = a[i]; 
        } else if (res[i % k] != a[i]) {
            res[i % k] = -2;
        }
    }
    for (int i : res) {
        if (i != -1 && i != -2)
            return true;
    }
    return false;
}

const int inf = 1e9 + 228;

int solve(vector<int> a) {
    int n = a.size();
    int ans = inf;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (check(a, n, i))
                ans = min(ans, i);
            if (check(a, n, n / i))
                ans = min(ans, n / i);
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> used(n);
    int ans = inf;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            vector<int> c;
            int j = i;
            while (!used[j]) {
                used[j] = 1;
                c.push_back(a[j]);
                j = p[j];
            }
            ans = min(ans, solve(c));
        }
    }
    cout << ans << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE;
}