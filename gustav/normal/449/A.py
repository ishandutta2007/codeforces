n, m, k = [int(i) for i in raw_input().split()]

def f(n, m, k): # sve na n, ostatak na m
  a = min(k, n - 1)
  k -= a
  b = min(k, m - 1)
  k -= a
  return (n / (a + 1)) * (m / (b + 1))

if k > n - 1 + m - 1:
  print -1
else:
  print max(f(n, m, k), f(m, n, k))