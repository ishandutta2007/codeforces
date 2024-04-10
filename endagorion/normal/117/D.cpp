    #include <iostream>
    #include <cmath>
    #include <cstdio>
    #include <vector>
    #include <set>
    #include <algorithm>
    #include <string>
    #include <cstring>
    #include <cstdlib>

    using namespace std;

    long long sum2(long long u, long long mod) {
        if (u % 2 == 0) {
            long long m = (u / 2) % mod;
            return (m * ((u + 1) % mod)) % mod;
        } else {
            long long m = ((u + 1) / 2) % mod;
            return (m * (u % mod)) % mod;
        }
    }

    long long _floor(long long x) {
        if (x >= 0) {
            return x / 2;
        } else {
            return x / 2 + x % 2;
        }
    }

    long long _ceil(long long x) {
        if (x >= 0) {
            return x / 2 + x % 2;
        } else {
            return x / 2;
        }
    }

    long long query(long long n, long long p, long long u, long long v, long long c, long long d, long long mod) {
        if (p == 0) {
            return 0;
        }
       
        if (p == n) {
            long long low = u;
            low = max(low, (long long)0);
            low = min(low, n);
            long long high = v;
            high = min(high, n - 1);
            high = max(high, (long long)-1);
            long long res = (sum2(high, mod) - sum2(low - 1, mod) + mod) % mod;
            res = (res * d + c * ((high - low + 1) % mod + mod)) % mod;
            return res;
        }

        long long even = _ceil(n);
        if (p <= even) {
            return query(even, p, _ceil(u), _floor(v), c, (2 * d) % mod, mod);
        } else {
            long long res = query(even, even, _ceil(u), _floor(v), c, (2 * d) % mod, mod);
            res = (res + query(n - even, p - even, _ceil(u - 1), _floor(v - 1), (c + d) % mod, (2 * d) % mod, mod)) % mod;
            return res;
        }
    }

    int main() {
        long long n, mod;
        int m;
        cin >> n >> m >> mod;
        for (int i = 0; i < m; ++i) {
            long long l, r, u, v;
            cin >> l >> r >> u >> v;
            cout << (query(n, r, u - 1, v - 1, 1, 1, mod) - query(n, l - 1, u - 1, v - 1, 1, 1, mod) + mod) % mod << '\n';
        }
       
        return 0;
    }