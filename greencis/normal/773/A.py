def gcd(a, b):
	if a == 0:
		return [b, 0, 1]
	d = gcd(b % a, a)
	return [d[0], d[2] - (b // a) * d[1], d[1]]

t = int(input())
while t > 0:
	t -= 1
	x, y, p, q = map(int, input().split())
	if p == q:
		if x == y:
			print(0)
		else:
			print(-1)
		continue
	if p == 0:
		if x == 0:
			print(0)
		else:
			print(-1)
		continue
	a = p - q
	b = p
	c = q * x - p * y
	g, xa, ya = gcd(abs(a), abs(b))
	if c % g != 0:
		print(-1)
	else:
		xa *= c // g
		ya *= c // g
		if a < 0:
			xa = -xa
		if b < 0:
			ya = -ya
		if xa < 0:
			gaps = (-xa + (b // g) - 1) // (b // g)
			xa += gaps * (b // g)
			ya -= gaps * (a // g)
		if ya < 0:
			gaps = (-ya + (-a // g) - 1) // (-a // g)		
			xa += gaps * (b // g)
			ya -= gaps * (a // g)
		#print(xa, ya, a, b, c)
		if xa < 0 or ya < 0:
			print(-1)
		else:
			addon = min(xa // (b // g), ya // (-a // g))
			xa -= addon * (b // g)
			ya += addon * (a // g)
			print(xa + ya)