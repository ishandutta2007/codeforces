a = []
r = [0] * 200200

def bsearch(x):
  l = 0
  r = len(a)
  m = 0
  while l < r:
    m = (l+r)>>1
    if a[m] > x:
      r = m
    else:
      l = m + 1
  return l

raw_input()
a = map(int, raw_input(). split())
b = map(int, raw_input(). split())
a.sort()

for i in xrange(len(b)):
  print bsearch(b[i]),