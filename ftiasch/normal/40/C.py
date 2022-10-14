# Codeforces Beta Round #39
# Problem C -- Berland Square
n, x, m, y = map(int, raw_input().split())
if x > y:
	x, y, n, m = y, x, m, n
r, i = n + 1, 1
while i <= m:
	ly, ry = y - i - x, y + i - x
	if ly >= n or ly <= -n:
		r += 1
	elif ly >= 0 and ry >= 0:
		ry = min(n, ry - 1)
		r += 2 * (ry - ly)
	else:
		ry = min(n, ry - 1)
		r += 2 * (ry + ly) + 1
	i += 1
print r