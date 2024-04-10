#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int N = 100000;
const int MOD = (int)1e9 + 7;

int t[N + 1], l[N + 1], fact[N + 1], inv_fact[N + 1], POW[N + 1];
char buffer[N + 1];

int inverse(int a)
{
    return a == 1 ? 1 : (long long)(MOD - MOD / a) * inverse(MOD % a) % MOD;
}

std::vector<int> precompute(int l)
{
    std::vector<int> result(N + 1);
    for (int i = l; i <= N; ++ i) {
        result[i] = result[i - 1];
        result[i] += (long long)fact[i - 1] * inv_fact[i - l] % MOD * inv_fact[l - 1] % MOD * POW[i] % MOD;
        if (result[i] >= MOD) {
            result[i] -= MOD;
        }
    }
    return result;
}

int quick_POW(int a, int n)
{
    int result = 1;
    while (n) {
        if (n & 1) {
            result = (long long)result * a % MOD;
        }
        a = (long long)a * a % MOD;
        n >>= 1;
    }
    return result;
}

int main()
{
    fact[0] = 1;
    for (int i = 1; i <= N; ++ i) {
        fact[i] = (long long)fact[i - 1] * i % MOD;
    }
    for (int i = 0; i <= N; ++ i) {
        inv_fact[i] = inverse(fact[i]);
    }
    POW[0] = 1;
    int base = 25LL * inverse(26) % MOD;
    for (int i = 1; i <= N; ++ i) {
        POW[i] = (long long)POW[i - 1] * base % MOD;
    }
    int q;
    scanf("%d%s", &q, buffer);
    t[0] = 1;
    l[0] = strlen(buffer);
    std::vector<int> values;
    values.push_back(l[0]);
    for (int i = 1; i <= q; ++ i) {
        scanf("%d", t + i);
        if (t[i] == 1) {
            scanf("%s", buffer);
            l[i] = strlen(buffer);
            values.push_back(l[i]);
        } else {
            scanf("%d", l + i);
        }
    }
    std::sort(values.begin(), values.end());
    values.erase(std::unique(values.begin(), values.end()), values.end());
    std::vector<std::vector<int>> table;
    for (auto&& v : values) {
        table.push_back(precompute(v));
    }
    int current_l = l[0];
    for (int i = 1; i <= q; ++ i) {
        if (t[i] == 1) {
            current_l = l[i];
        } else {
            int index = std::lower_bound(values.begin(), values.end(), current_l) - values.begin();
            int result = table[index][l[i]];
            printf("%d\n", (int)((long long)result * quick_POW(26, l[i]) % MOD * inverse(quick_POW(25, current_l)) % MOD));
        }
    }
}