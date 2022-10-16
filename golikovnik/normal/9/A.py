def gcd(a, b):
  return gcd(b, a % b) if b else a

y, w = map(int, input().split())
mx = max(y, w)
q = 6
p = q - mx + 1
g = gcd(p, q)
q /= g
p /= g
print("%d/%d" % (p, q))