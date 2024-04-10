t = int(input())
for _ in range(t):
	s, a, b, c = map(int, input().split())
	can = s // c
	ans = can + (can // a * b)
	print(ans)