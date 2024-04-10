// Codeforces Round #104
// PRoblem C -- Lucky Subsequence
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int N = 111111;
const int MOD = 1000000007;

int n, m, factorial[N], ways[N];
map <int, int> lucky_count;

bool is_lucky(int n) {
    while (n) {
        if (n % 10 != 4 && n % 10 != 7) {
            return false;
        }
        n /= 10;
    }
    return true;
}

int inverse(int a) {
    int result = 1;
    for (int n = MOD - 2; n; n >>= 1) {
        if (n & 1) {
            result = ((long long)result * a) % MOD;
        }
        a = ((long long)a * a) % MOD;
    }
    return result;
}

int combine(int n, int k) {
    if (k <= n) {
        return (long long)factorial[n] * inverse(factorial[k]) % MOD
            * inverse(factorial[n - k]) % MOD;
    }
    return 0;
}

int main() {
    scanf("%d%d", &n, &m);
    factorial[0] = 1;
    for (int i = 1; i <= n; ++ i) {
        factorial[i] = ((long long)factorial[i - 1] * i) % MOD;
    }
    int unlucky_count = 0;
    for (int i = 0; i < n; ++ i) {
        int a_i;
        scanf("%d", &a_i);
        if (is_lucky(a_i)) {
            lucky_count[a_i] ++;
        } else {
            unlucky_count ++;
        }
    }
    memset(ways, 0, sizeof(ways));
    ways[0] = 1;
    for (map <int, int> :: iterator iter = lucky_count.begin();
            iter != lucky_count.end(); ++ iter) {
        for (int i = m; i >= 1; -- i) {
            ways[i] = (ways[i] 
                    + (long long)ways[i - 1] * iter->second) % MOD;
        }
    }
    int result = 0;
    for (int i = 0; i <= m; ++ i) {
        result = (result + (long long)combine(unlucky_count, m - i)
                * ways[i]) % MOD;
    }
    printf("%d\n", result);
    return 0;
}