def euclid(a, b):
	if b == 0:
		return (1, 0, a)
	else:
		(x, y, g) = euclid(b, a%b)
		return (y, x - a/b*y, g)

def modDivide(a, b, p):
	(x, y, g) = euclid(b, p)
	return a / g * (x + p) % p

def square(a):
	return a * a
def modPow(a, n, P):
	if n == 0:
		return 1
	if n % 2 == 1:
		return modPow(a, n-1, P) * a % P
	else:
		return square(modPow(a, n/2, P)) % P

def fac(n):
	ans = 1
	for i in range(1, n+1):
		ans = ans * i % P
	return ans

P = 1000000007
n = int(raw_input())
s = raw_input()
l = []
for i in 'ACGT':
	l.append(len(filter(lambda x: x == i, s)))
l.sort()
cnt = 0
for i in l:
	if i == l[-1]:
		cnt += 1
print modPow(cnt, n, P)