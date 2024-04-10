def euclid(a, b):
	if b == 0:
		return (1, 0, a)
	else:
		(x, y, g) = euclid(b, a%b)
		return (y, x - a/b*y, g)

def modDivide(a, b, p):
	(x, y, g) = euclid(b, p)
	return a / g * (x + p) % p

def comb(n, k):
	return modDivide(fac[n], fac[k] * fac[n-k] % P, P)

P = 1000000007
n, k = map(int, raw_input().split())
d = map(int, list(raw_input()))
fac = [1]
for i in range(1, n):
	fac.append(fac[-1] * i % P)
f = []
ten = [1]
s = 0
for i in range(0, n-k):
	t = comb(n-i-2, k-1) * ten[-1] % P
	ten.append(ten[-1] * 10 % P)
	s = (s + t) % P
	f.append(s)
ans = 0
for i in range(n):
	ans += d[i] * f[min(n-1-i, n-1-k)]
	if i >= k:
		w = n - 1 - i
		ans -= d[i] * comb(n-w-2, k-1) * ten[w]
		ans += d[i] * comb(n-w-1, k) * ten[w]
	ans %= P
if k == 0:
	ans = 0
	for i in d:
		ans = ans * 10 + i
		ans %= P
print ans