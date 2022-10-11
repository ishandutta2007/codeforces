import sys

def solve():
	n = int(sys.stdin.readline())
	a = list(map(int, sys.stdin.readline().split()))
	
	a.sort()
	if (a[0] == 0):
		print("NO")
		return
		
	for i in range(2 * n):
		if (a[i] % 2 == 1):
			print("NO")
			return
	
	for i in range(n):
		if (a[2 * i] != a[2 * i + 1]):
			print("NO")
			return
	
	for i in range(n - 1):
		if (a[2 * i] == a[2 * i + 2]):
			print("NO")
			return
			
	b = [a[2 * i] / 2 for i in range(n)]
	b.reverse()
	c = [0] * n
	tot = 0
	for i in range(n):
		b[i] -= tot
		within = n - i
		if (b[i] % within != 0 or b[i] <= 0):
			print("NO")
			return
		c[i] = int(b[i] / within)
		tot += c[i]
		
	for i in range(n - 1):
		if (c[i] <= c[i + 1]):
			print("NO")
			return
	
	print("YES")

t = int(sys.stdin.readline())
for tc in range(t):
	solve()