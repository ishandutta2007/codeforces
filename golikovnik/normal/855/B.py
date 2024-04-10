n, p, q, r = map(int, input().split())
a = [int(i) for i in input().split()]
pp = float("-inf")
qq = float("-inf")
rr = float("-inf")
for x in a:
	pp = max(pp, x * p)
	qq = max(qq, pp + x * q)
	rr = max(rr, qq + x * r)
print(rr)