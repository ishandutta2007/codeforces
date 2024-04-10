#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>

using namespace std;

const int MOD = 998244353;
const int MAXN = 200000;

int f[1 + MAXN], fenwick[1 + MAXN], fact[1 + MAXN];

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int raise(int base, int power) {
    int ans = 1;
    while (power) {
        if (power & 1) {
            ans = 1LL * ans * base % MOD;
        }
        base = 1LL * base * base % MOD;
        power >>= 1;
    }
    return ans;
}

void update(int x, int y) {
    for (; x <= MAXN; x += (x & -x)) {
        add(fenwick[x], y);
    }
}

int query(int x) {
    int ans = 0;
    for (; x > 0; x -= (x & -x)) {
        add(ans, fenwick[x]);
    }
    return ans;
}

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        f[x]++;
        fact[i] = 1LL * fact[i - 1] * i % MOD;
    }
    int curr = fact[n];
    for (int i = 1; i <= MAXN; i++) {
        if (f[i] > 0) {
            update(i, f[i]);
            curr = 1LL * curr * raise(fact[f[i]], MOD - 2) % MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int t;
        cin >> t;
        if (n == 0) {
            add(ans, 1);
            break;
        }
        curr = 1LL * curr * raise(n, MOD - 2) % MOD;
        n--;
        add(ans, 1LL * curr * query(t - 1) % MOD);
        if (f[t] == 0) {
            break;
        }
        update(t, MOD - 1);
        curr = 1LL * curr * f[t] % MOD;
        f[t]--;
    }
    cout << ans << "\n";
    return 0;
}