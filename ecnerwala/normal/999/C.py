n,k = map(int, input().split())
s = [*input()]
from collections import *
cnt = Counter(s)
for c in 'abcdefghijklmnopqrstuvwxyz':
  if cnt[c] < k:
    k -= cnt[c]
  else:
    break
res = 0
t = []
for a in s:
    if a < c:
      pass
    elif k and a == c:
      k -= 1
    else:
      t.append(a)
print(''.join(t))