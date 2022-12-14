#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll mod = 1e9 + 7;
const int N = 2e5 + 1;
int prime[N];

map<int, int> a[N];
map<int, int> cnt[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    prime[1] = 1;
    for (int i = 2; i < N; i++) {
        if (prime[i]) continue;

        for (int j = i; j < N; j += i) {
            prime[j] = i;
        }
    }

    int n, q;
    cin >> n >> q;
    ll gcd = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        while (x != 1) {
            int d = prime[x];
            x /= d;

            a[i][d]++;
            cnt[d][a[i][d]]++;
            if (cnt[d][a[i][d]] == n) gcd = gcd * d % mod;
        }
    }

    while (q--) {
        int i, x;
        cin >> i >> x;
        i--;

        while (x != 1) {
            int d = prime[x];
            x /= d;

            a[i][d]++;
            cnt[d][a[i][d]]++;
            if (cnt[d][a[i][d]] == n) gcd = gcd * d % mod;
        }

        cout << gcd << '\n';
    }
}