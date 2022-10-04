#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool prime(int x) {
    for (int i = 2; i * i <= x; ++i) if (x % i == 0) return false;
    return true;
}

vector <int> p;

void precalc() {
    for (int i = 2; i <= 70; ++i) {
        if (prime(i)) p.push_back(i);
    }   
}

int get(int x) {
    int res = 0;
    for (int i = 0; i < (int)p.size(); ++i) {
        while (x % p[i] == 0) {
            res ^= (1 << i);
            x /= p[i];
        }
    }
    return res;
}

const int K = 20;

const int md = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    precalc();
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> g(K, -1);
    for (int i = 0; i < n; ++i) {
        int cr = get(a[i]);
        for (int j = K - 1; j >= 0; --j) {
            if (cr & (1 << j)) {
                if (g[j] == -1) {
                    g[j] = cr;
                    break;
                }
                cr ^= g[j];
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < K; ++i) {
        if (g[i] != -1) ++cnt;
    }
    cnt = n - cnt;
    int ans = 1;
    for (int i = 0; i < cnt; ++i) {
        ans = (ans * 2) % md;
    }
    cout << (ans - 1 + md) % md << '\n';
}