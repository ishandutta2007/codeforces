#include <iostream>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

template <int MOD>
struct ModInt {
    using lint = long long;
    int val;

    // constructor
    ModInt(lint v = 0) : val(v % MOD) {
        if (val < 0) val += MOD;
    };

    // unary operator
    ModInt operator+() const { return ModInt(val); }
    ModInt operator-() const { return ModInt(MOD - val); }
    ModInt inv() const { return this->pow(MOD - 2); }

    // arithmetic
    ModInt operator+(const ModInt& x) const { return ModInt(*this) += x; }
    ModInt operator-(const ModInt& x) const { return ModInt(*this) -= x; }
    ModInt operator*(const ModInt& x) const { return ModInt(*this) *= x; }
    ModInt operator/(const ModInt& x) const { return ModInt(*this) /= x; }
    ModInt pow(lint n) const {
        auto x = ModInt(1);
        auto b = *this;
        while (n > 0) {
            if (n & 1) x *= b;
            n >>= 1;
            b *= b;
        }
        return x;
    }

    // compound assignment
    ModInt& operator+=(const ModInt& x) {
        if ((val += x.val) >= MOD) val -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& x) {
        if ((val -= x.val) < 0) val += MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& x) {
        val = lint(val) * x.val % MOD;
        return *this;
    }
    ModInt& operator/=(const ModInt& x) { return *this *= x.inv(); }

    // compare
    bool operator==(const ModInt& b) const { return val == b.val; }
    bool operator!=(const ModInt& b) const { return val != b.val; }
    bool operator<(const ModInt& b) const { return val < b.val; }
    bool operator<=(const ModInt& b) const { return val <= b.val; }
    bool operator>(const ModInt& b) const { return val > b.val; }
    bool operator>=(const ModInt& b) const { return val >= b.val; }

    // I/O
    friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept {
        lint v;
        is >> v;
        x = v;
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }
};

template <class T>
struct Combination {
    int max_n;
    std::vector<T> f, invf;

    explicit Combination(int n)
        : max_n(n), f(n + 1), invf(n + 1) {
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] * i;
        }

        invf[max_n] = f[max_n].inv();
        for (int i = max_n - 1; i >= 0; --i) {
            invf[i] = invf[i + 1] * (i + 1);
        }
    }

    T fact(int n) const { return n < 0 ? T(0) : f[n]; }
    T invfact(int n) const { return n < 0 ? T(0) : invf[n]; }
    T perm(int a, int b) const {
        return a < b || b < 0 ? T(0) : f[a] * invf[a - b];
    }
    T binom(int a, int b) const {
        return a < b || b < 0 ? T(0) : f[a] * invf[a - b] * invf[b];
    }
};

constexpr int MOD = 1000000007;
using mint = ModInt<MOD>;
const Combination<mint> C(5000);

constexpr int D = 2000;
constexpr int H = 6000;

void solve() {
    int n, m, r;
    std::cin >> n >> m >> r;

    auto grid = vec(H, vec(H, 0));
    std::vector<int> xs(n), ys(n), bs(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> xs[i] >> ys[i] >> bs[i];
        xs[i] += D, ys[i] += D;
        ++grid[xs[i]][ys[i]];
    }

    for (int x = 0; x < H; ++x) {
        for (int y = 1; y < H; ++y) {
            grid[x][y] += grid[x][y - 1];
        }
    }
    for (int x = 1; x < H; ++x) {
        for (int y = 0; y < H; ++y) {
            grid[x][y] += grid[x - 1][y];
        }
    }

    auto getsum = [&](int lx, int ly, int rx, int ry) {
        if (lx > rx || ly > ry) return 0;
        --lx, --ly;
        return grid[rx][ry] - grid[lx][ry] - grid[rx][ly] + grid[lx][ly];
    };

    mint ans = 0;
    {
        mint bsum = 0;
        for (auto b : bs) bsum += b;
        ans = bsum * bsum * C.binom(n, m);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int ki = getsum(xs[i] - r, ys[i] - r, xs[i] + r, ys[i] + r);
            int kj = getsum(xs[j] - r, ys[j] - r, xs[j] + r, ys[j] + r);
            int kij = ki + kj -
                      getsum(std::max(xs[i] - r, xs[j] - r),
                             std::max(ys[i] - r, ys[j] - r),
                             std::min(xs[i] + r, xs[j] + r),
                             std::min(ys[i] + r, ys[j] + r));

            ans -= (C.binom(n - ki, m) + C.binom(n - kj, m) - C.binom(n - kij, m)) * bs[i] * bs[j];
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}