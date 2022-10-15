def solve(N, M):
    ans = 0
    while M > 1:
        ans += N // M
        N, M = M, N % M
    if M == 0: return 1000000
    return N - 1 + ans

N = int(input())
ans = 1000000
for M in range(1, N + 1):
    ans = min([ans, solve(N, M)])
print(ans)