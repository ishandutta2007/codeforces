x = int(input())
t = input().split()
h, m = int(t[0]), int(t[1])
i = 0
while True:
	if '7' in str(h) or '7' in str(m):
		print(i)
		exit(0)
	m -= x
	if m < 0:
		m += 60
		h -= 1
	if h < 0:
		h += 24
	i += 1