MOD = 1000000007
def main():
    s = input()
    n = len(s)
    zero = [0] * n
    for i in range(n):
        if s[i] == '0':
            zero[i] = zero[i-1] + 1 if i else 1
    nxt, dp = [0] * (n+2), [0] * (n+2)
    for i in range(n+1):
        nxt[i] = n
    for i in range(n-1, -1, -1):
        dp[i] = ((zero[i] <= zero[n-1]) + dp[nxt[0]] + dp[nxt[zero[i] + 1]]) % MOD
        nxt[zero[i]] = i
    ans = n if nxt[0] >= n else dp[nxt[0]] * (nxt[0] + 1) % MOD
    print(ans)

main()