n, k = map(int, input().split())
s = input()

length = 0
for i in range(1, n):
	length = n - i
	if s[i:n] == s[0:length]:
		break
else:
	length = 0

ans = s
for i in range(1, k):
	ans += s[length:n]
print(ans)