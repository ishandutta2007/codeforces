#include <bits/stdc++.h>

using namespace std;
typedef unsigned int ll;

#define SZ 3085

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

ll N, a, b, c, d, ans, z;
ll pot[SZ];
int pr[SZ];

ll f(ll x) {
    ll ret = (a * x + b);
    ret = (ret * x + c);
    ret = (ret * x + d);
    return ret;
}

void jonson(int limit) {
    if(limit < 2) return;
    z = 1;

    int sqrt = (int) std::sqrt(limit);
    int segment_size = sqrt;

    ans = (ans + (N / pot[0]) * f(2));
    int s = 3, n = 3;

    char is_prime[sqrt + 1];
    memset(is_prime, 1, sizeof is_prime);

    for (int i = 2; i * i <= sqrt; ++i)
        if (is_prime[i])
            for (int j = i * i; j <= sqrt; j += i)
                is_prime[j] = 0;

    char sieve[segment_size];
    int primes[SZ], next[SZ], id = 0;

    for (int low = 0; low <= limit; low += segment_size) {
        memset(sieve, 1, sizeof sieve);
        int high = min(low + segment_size - 1, limit);

        for (; s * s <= high; s += 2) {
            if (is_prime[s]) {
                primes[id] = (s);
                next[id++] = (s * s - low);
            }
        }

        for (int i = 0; i < id; ++i) {
            int j = next[i];
            for (int k = primes[i] << 1; j < segment_size; j += k)
                sieve[j] = 0;
            next[i] = j - segment_size;
        }

        for (; n <= high; n += 2)
            if (sieve[n - low]) {
                if(limit == N && z < SZ) {
                    pr[z] = n;
                    pot[z++] = n;
                } else z++;
                ans = (ans + (N / ((z <= SZ) ? pot[z-1] : n)) * f(n));
            }
    }
}

int main() {
    scanf("%u %u %u %u %u", &N, &a, &b, &c, &d);

    pot[0] = pr[0] = 2;
    jonson(N);
    for(int p = 2; p < 30; p++) {
        for(int i = 0;; i++) {
            long long tmp = 1LL * pot[i] * pr[i];
            pot[i] = pot[i] * pr[i];
            if(tmp > N) {
                if(i) jonson(pr[i-1]);
                break;
            }
        }
    }

    printf("%u\n", ans);
    return 0;
}