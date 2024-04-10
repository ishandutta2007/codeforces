def check(mn, n, k, s):
	cur = 0
	k -= 1
	while cur + 1 < n:
		prv = cur
		cur = min(n - 1, cur + mn)
		while s[cur] == '1':
			cur -= 1
		if prv == cur:
			return False
		k -= 1
	return k >= 0

n, k = map(int, input().split())
s = input()
L = 1
R = n - 1
while L < R:
	mid = (L + R) // 2
	if not check(mid, n, k, s):
		L = mid + 1
	else:
		R = mid
print(L - 1)