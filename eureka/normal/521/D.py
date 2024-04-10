def euclid(a, b):
	if b == 0:
		return (1, 0, a)
	else:
		(x, y, g) = euclid(b, a%b)
		return (y, x - a//b*y, g)

def modDivide(a, b, p):
	(x, y, g) = euclid(b, p)
	return a // g * (x + p) % p

def comb(n, k):
	return modDivide(fac[n], fac[k] * fac[n-k] % P, P)

k, n, m = list(map(int, input().split()))
a = list(map(int, input().split()))
skill = []
l = [[[], [], []] for i in range(k)]
for j in range(n):
	t = list(map(int, input().split()))
	skill.append(t)
	(t, i, b) = t
	l[i-1][t-1].append((b, j+1))
for i in range(k):
	for j in range(3):
		l[i][j].sort(reverse=True)
op = []
for i in range(k):
	t = l[i][1][:]
	if len(l[i][0]) != 0 and l[i][0][0][0] > a[i]:
		t.append((l[i][0][0][0] - a[i], l[i][0][0][1]))
		t.sort(reverse=True)
	s = a[i]
	for (add, index) in t:
		op.append(((s+add)/s, index))
		s += add
	for (mul, index) in l[i][2]:
		op.append((mul, index))
op.sort(reverse=True)
st = set(map(lambda t : t[1], op[:m]))
print(len(st))
for i in range(k):
	for j in range(3):
		for (mul, index) in l[i][j]:
			if index in st:
				print(index, end=' ')