s = bytes(input(), 'utf-8')
mod = int(input())
n = len(s)

def addMod(a, b):
	return (a + b) % mod

def subMod(a, b):
	return (a + mod - b) % mod

def mulMod(a, b):
	return (a * b) % mod

def extGcd(a, b):
	if a == 0:
		return (0, 1, b)
	(x1, y1, d) = extGcd(b % a, a)
	x = y1 - (b // a) * x1
	y = x1
	return (x, y, d)

res = mod

pref = 0
suf = 0
pows = [1]

for i in range(1, n+1):
	pows.append(mulMod(pows[-1], 10))

for i in range(0, n):
	pref = mulMod(pref, 10)
	pref = addMod(pref, s[i] - 48)
	
for i in range(0, n):
	if s[i] != 48:
		res = min(res, addMod(suf, mulMod(pref, pows[i])))
	pref = subMod(pref, mulMod(pows[n - i - 1], s[i] - 48))
	suf = mulMod(suf, 10)
	suf = addMod(suf, s[i] - 48)
	
print(res)