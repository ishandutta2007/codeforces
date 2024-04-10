import sys

sys.setrecursionlimit(100000)

def cycle(p, i, v):
  if i in v: return v
  v.add(i)
  return cycle(p, p[i], v)

def cc(p):
  vis = set()
  cnt = 0
  for i in range(len(p)):
    if not i in vis:
      vis = vis.union(cycle(p, i, set()))
      cnt += 1
  return cnt

n = int(raw_input())
p = [int(i) - 1 for i in raw_input().split()]
m = n - int(raw_input())

c = cc(p)
sol = abs(c - m)
rec = []

if c > m:
  vis = cycle(p, 0, set())
  for i in range(len(p)):
    if i in vis: continue
    vis = vis.union(cycle(p, i, set()))
    c -= 1
    rec.append((0, i))
    if c == m: break
elif c < m:
  for i in range(len(p)):
    C = cycle(p, i, set())
    while len(C) > 1:
      C.remove(i)
      rec.append((i, min(C)))
      c += 1
      if c == m: break
      p[i], p[min(C)] = p[min(C)], p[i]
      C = cycle(p, i, set())
    if c == m: break

print sol
for pp in rec:
  print pp[0] + 1, pp[1] + 1, 
print ''