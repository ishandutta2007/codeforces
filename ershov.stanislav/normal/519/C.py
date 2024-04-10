import sys

#sys.stdin = open('in.txt', 'rt')

n, m = map(int, input().split())

ans = 0
for a in range(min(n + 1, m // 2 + 1)):
    ans = max(ans, a + min((n - a) // 2, m - 2 * a))
print(ans)