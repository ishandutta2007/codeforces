MOD = 10 ** 9 + 9
n, m, k = map(int, raw_input().split())
if k * (n - m + 1) - 1 >= n:
    print m
else:
    consecutive = n - k * (n - m)
    print ((2 * k * pow(2, consecutive / k, MOD) - 2 * k + consecutive % k + (k - 1) * (n - m)) % MOD + MOD) % MOD