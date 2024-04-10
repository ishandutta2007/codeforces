n,m = map(int, input().split())
assert n % m == 0
k = n // m
a = [*map(int, input().split())]
inds = [[] for r in range(m)]
for i,v in enumerate(a):
  inds[v%m].append(i)
extras = []
for r in range(2*m):
  r %= m
  if len(inds[r]) == k: continue
  elif len(inds[r]) > k:
    extras.extend(inds[r][k:])
    inds[r] = inds[r][:k]
  elif len(inds[r]) < k:
    for _ in range(min(k-len(inds[r]), len(extras))):
      inds[r].append(extras.pop())
  else: assert False
res = 0
for r in range(m):
  for i in inds[r]:
    if a[i] % m > r:
      res += m - (a[i] % m)
      a[i] += m - (a[i] % m)
    res += (r - a[i] % m)
    a[i] += (r - a[i] % m)
print(res)
print(' '.join(map(str, a)))