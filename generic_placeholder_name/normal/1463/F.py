#ecnerwala's algorithm

import math
def solve(n, x, y):
    g = math.gcd(x, y)
    if g != 1:
        return solve(n // g + 1, x // g, y // g) * (n % g) + solve(n // g, x // g, y // g) * (g - n % g)
    p = x + y
    weights = [n // p] * p
    for i in range(p):
        if (i * x) % p < n % p:
            weights[i] += 1
    ans = -n
    for i in range(2):
        dp = [-n, -n]
        dp[i] = 0
        for w in weights:
            dp = [max(dp[0], dp[1]), dp[0] + w]
        ans = max(ans, dp[i])
    return ans

def main():
    n, x, y = [int(x) for x in input().split()]
    print(solve(n, x, y))

main()