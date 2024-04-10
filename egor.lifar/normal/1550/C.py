t = int(input())
def dist(a, b, c, d):
	return abs(a - c) + abs(b - d)
def bad(a, b, c, d, e, f):
	return dist(a, b, c, d) == dist(a, b, e, f) + dist(e, f, c, d) or dist(a, b, e, f) == dist(a, b, c, d) + dist(e, f, c, d) or dist(e, f, c, d) == dist(a, b, e, f) + dist(a, b, c, d)
for i in range(t):
	n = int(input())
	a = []
	a = (str(input())).split(' ')
	ans = 0
	for i in range(n):
		j = i
		f = []
		while j < n:
			f.append((int(a[j]), j))
			ok = True
			for ise in range(len(f)):
				for js in range(ise + 1, len(f)):
					for k in range(js + 1, len(f)):
						if bad(f[ise][0], f[ise][1], f[js][0], f[js][1], f[k][0], f[k][1]):
							ok = False
							break
					if not ok:
						break
				if not ok:
					break
			if not ok:
				break
			j += 1
		ans += j - i
	print(ans)