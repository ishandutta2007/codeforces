#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

const int mod = 1000000007;

int add32(int x, int y) {
    int res = x + y;
    if (res >=  mod) res -= mod;
    return res;
}

int sub32(int x, int y) {
    int res = x - y;
    if (res < 0) res += mod;
    return res;
}

int mul32(int x, int y) {
    return (int64_t(x) * y) % mod;
}

template<class T>
std::pair<T, T> gcd2(T x, T y) {
    if (x == 0) {
        return {0, 1};
    }
    T s = y / x;
    std::pair<T, T> res = gcd2(y % x, x);
    return {res.second - s * res.first, res.first};
}

template<class T>
T inv(T x) {
    x = x % mod;
    if (x < 0) {
        x += mod;
    }
    std::pair<T, T> res = gcd2(x, mod);
    if (res.first < 0) {
        res.first += mod;
    }
    if (res.first >= mod) {
        res.first -= mod;
    }
    return res.first;
}

struct Solution {
    int n;
    int64_t T;
    std::vector<int64_t> ts;

    std::vector<int> pow2;
    std::vector<int> ipow2;
    std::vector<int> fact;
    std::vector<int> ifact;
    int inv2;

    void precalc() {
        pow2.resize(n + 1);
        pow2[0] = 1;
        for (int i = 1; i < n; i++) {
            pow2[i] = mul32(pow2[i - 1], 2);
        }
        ipow2.resize(n + 1);
        ipow2[0] = 1;
        inv2 = inv(2);
        for (int i = 1; i < n; i++) {
            ipow2[i] = mul32(ipow2[i - 1], inv2);
        }
        fact.resize(n + 1);
        ifact.resize(n + 1);
        fact[0] = 1;
        ifact[0] = 1;
        for (int i = 1; i < n; i++) {
            fact[i] = mul32(fact[i - 1], i);
            ifact[i] = inv(fact[i]);
        }
    }

    int binProb(int k, int n) {
        return mul32(ipow2[n], mul32(fact[n], mul32(ifact[k], ifact[n - k])));
    }

    void run(std::istream &in, std::ostream &out) {
        in >> n >> T;
        ts.resize(n);
        for (int i = 0; i < n; i++) {
            in >> ts[i];
        }
        ts.push_back(T + 1);
        n++;
        precalc();
        int64_t sum = 0;
        int before = 1;
        int ans = 0;
        for (int i = 0; i < n && before > 0; i++) {
            int64_t sumNext = sum + ts[i];
            int next = (int)std::min<int64_t>(before + 1, T - sumNext + 1);
            if (next <= before) {
                int prob = next > 0 ? mul32(inv2, binProb(next - 1, i)) : 0;
                for (int j = std::max(next, 0); j < before; j++) {
                    prob = add32(prob, binProb(j, i));
                }
                ans = add32(ans, mul32(prob, i));
            }
            before = next;
            sum = sumNext;
        }
        out << ans << "\n";
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}