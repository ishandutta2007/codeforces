s = input().split()
n, L = int(s[0]), int(s[1])
c = list(map(int, input().split()))
for i in range(n - 1, 0, -1):
	if c[i] < c[i - 1]:
		c[i - 1] = c[i]
for i in range(1, n):
	if c[i] > c[i - 1] * 2:
		c[i] = c[i - 1] * 2
while len(c) < 31:
	c.append(c[-1] * 2)
s = set()
ans = 0
for i in range(30, -1, -1):
	if L == 0:
		break
	if L >= pow(2, i):
		L -= pow(2, i)
		ans += c[i]
	else:
		s.add(ans + c[i])
s.add(ans);
print(min(s))