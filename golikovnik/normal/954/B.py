n = int(input())
s = input()
ans = n
for i in range(n):
	if 2 * i <= n and s[:i] == s[i: 2 * i]:
		ans = min(ans, n - i + 1)
print(ans)