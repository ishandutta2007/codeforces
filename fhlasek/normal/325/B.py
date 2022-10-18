
A = long(raw_input())

def count(n, k): return n * (n - 1) / 2 + n * ((1 << k) - 1)

ans = []
for k in range(0, 60):
  left = 1
  right = 10**11
  while left != right:
    middle = (left + right) / 2
    if (count(middle, k) < A): left = middle + 1
    else: right = middle
  n = left * (1 << k)
  if (left % 2 != 0) and (count(left, k) == A) and (n not in ans): ans.append(n)

if len(ans):
  ans.sort()
  for i in ans: print i,
  print ""
else: print -1