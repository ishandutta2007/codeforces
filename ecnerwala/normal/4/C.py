from collections import defaultdict
n = int(input())
d = defaultdict(int)
def f(s):
  if s not in d:
    d[s] = 1
    return 'OK'
  else:
    while s + str(d[s]) in d:
      d[s] += 1
    res = s + str(d[s])
    d[res] = 1
    return res
print('\n'.join(f(input()) for i in range(n)))