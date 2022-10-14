n = int(input())
ans = [n] * (2 * n)
for i in range(1, n + 1):
    x = i // 2 if i & 1 else n - 1 + i // 2
    y = x + n - i
    ans[x], ans[y] = i, i
print(*ans)