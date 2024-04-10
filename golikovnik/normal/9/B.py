from fractions import Fraction
from math import sqrt

n, vb, vs = map(int, input().split())
a = [int(i) for i in input().split()]
xu, yu = map(int, input().split())
mn_time = float("inf")
mn_dist = float("inf")
ind = -1
eps = 1e-8
for i, pos in enumerate(a[1:]):
  time_to_pos = pos / vb
  dist = sqrt((pos - xu) ** 2 + yu ** 2)
  time_to_finish = dist / vs
  time = time_to_pos + time_to_finish
  if time < mn_time:
    mn_time = time
    mn_dist = dist
    ind = i + 2
  elif abs(time - mn_time) < eps:
    if dist < mn_dist:
      mn_time = time
      mn_dist = dist
      ind = i + 2
print(ind)