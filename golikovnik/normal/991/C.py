def read_input():
	return map(int, input().split())

n = int(input())

def eat(k, n):
	ans = 0
	while n >= k:
		ans += k
		n = max(0, (n - k) - (n - k) // 10)
	ans += n
	return ans

l = 1
r = n + 1

while r - l > 1:
	m = (l + r) >> 1
	if 2 * eat(m, n) >= n:
		r = m
	else:
		l = m

print(l if 2 * eat(l, n) >= n else l + 1)