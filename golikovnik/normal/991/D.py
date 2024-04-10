def read_input():
	return map(int, input().split())

a = [list(input()), list(input())]
ans = 0
n = len(a[0])

i = 0
while i + 1 < n:
	cnt = sum(c == 'X' for c in [a[0][i], a[1][i], a[0][i + 1], a[1][i + 1]])
	if cnt > 1:
		i += 1
		continue
	if cnt == 1:
		ans += 1
		i += 2
		continue
	ans += 1
	a[0][i + 1] = 'X'
	i += 1
print(ans)