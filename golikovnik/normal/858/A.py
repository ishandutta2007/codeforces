def gcd(x, y):
  while y:
    x %= y
    x, y = y, x
  return x

def lcm(x, y):
  return x // gcd(x, y) * y

n, k = map(int, input().split())
print(lcm(n, 10 ** k))