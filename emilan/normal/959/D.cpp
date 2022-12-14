#include <bits/stdc++.h>
using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

const int sieve_size = 5e6;

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    vt<int> primes;
    vt<bool> sieve(sieve_size);
    for (int i = 2; i < sz(sieve); i++) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (int j = i + i; j < sz(sieve); j += i)
                sieve[j] = true;
        }
    }

    vt<bool> used(sieve_size);
    vt<int> b(n);
    bool a_coprime = true;
    for (int i = 0, primes_idx = 0; i < n; i++) { 
        if (a_coprime) {
            for (;; a[i]++) {
                bool ok = true;
                vt<int> decomp;
                int t = a[i];
                for (int j = 2; j * j <= t; j++) {
                    if (t % j == 0) {
                        if (used[j]) {
                            ok = a_coprime = false;
                            break;
                        }

                        decomp.push_back(j);
                        t /= j;
                        while (t % j == 0) t /= j;
                    }
                }
                if (t != 1) {
                    if (used[t]) ok = a_coprime = false;
                    else decomp.push_back(t);
                }

                if (ok) {
                    for (int x : decomp) used[x] = true;
                    b[i] = a[i];
                    break;
                }
            }
        } else {
            while (used[primes[primes_idx]]) primes_idx++;
            b[i] = primes[primes_idx++];
        }
    }

    for (int x : b) cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}