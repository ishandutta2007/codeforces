from math import sqrt

n = int(input())
a = [int(i) for i in input().split()]
mx = float("-inf")
for x in a:
  if x < 0:
    mx = max(mx, x)
  elif not sqrt(x).is_integer():
    mx = max(mx, x)
print(mx)