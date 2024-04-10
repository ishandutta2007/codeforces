#include <cmath>
#include <iostream>
#include <vector>

template<int MOD = 0>
class PolyInter
{
public:
    PolyInter& init(const std::vector<int>& v, int m = 0)
    {
        mod_ = m, deg = v.size(), val = buf = v;
        inv.resize(std::max(2, deg));
        inv[1] = 1;
        for (int i = 2; i < deg; ++ i) {
            inv[i] = 1LL * (mod() - mod() / i) * inv[mod() % i] % mod();
        }
        return *this;
    }

    int eval(long long n)
    {
        long long b = 1;
        for (int i = 1; i < deg; ++ i) {
            b = b * residue(n - i + 1) % mod() * inv[i] % mod();
            buf[i] = b * val[i] % mod();
        }
        b = 1;
        int result = buf[deg - 1];
        for (int i = deg - 2; i >= 0; -- i) {
            b = (mod() - b) * inv[deg - 1 - i] % mod() * residue(n - i - 1) % mod();
            result += buf[i] * b % mod();
            if (result >= mod()) {
                result -= mod();
            }
        }
        return result;
    }

private:
    int mod() const {
        return MOD ? MOD : mod_;
    }

    int residue(long long x) const {
        x %= mod();
        return x < 0 ? x + mod() : x;
    }

    int mod_, deg;
    std::vector<int> inv, val, buf;
};

const int MOD = (int)1e9 + 7;
const int INV[] = {0, 1, (int)5e8 + 4, 333333336};

long long n;
int sn;

int add(int a, int b) {
    a += b;
    return a >= MOD ? a - MOD : a;
}

int calc2(long long x)
{
    x %= MOD;
    int tmp = 1LL * x * (x - 1) % MOD * INV[2] % MOD;
    return add(1LL * n % MOD * tmp % MOD, MOD - 2LL * tmp * (x - 2) % MOD * INV[3] % MOD);
}

int calc(int x, int y)
{
    long long s = 1LL * x * x + 1LL * y * y;
    return s > n ? 0 : add(sn, MOD - calc2(s));
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("D.in", "r", stdin);
#endif
    std::cin >> n;
    sn = calc2(n + 1);
    int y = sqrtl(n);
    PolyInter<MOD> poly;
    std::vector<int> values(8);
    int result = 0;
    for (int x = 0; 1LL * x * x <= n; ++ x) {
        while (1LL * x * x + 1LL * y * y > n) {
            y --;
        }
        values[0] = calc(x, 0);
        for (int j = 1; j < 8; ++ j) {
            int tmp = calc(x, j);
            values[j] = add(values[j - 1], add(tmp, tmp));
        }
        int tmp = poly.init(values).eval(y);
        result = add(result, tmp);
        if (x) {
            result = add(result, tmp);
        }
    }
    printf("%d\n", result);
}