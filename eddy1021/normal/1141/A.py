n, m = list(map(int, input().split()))
a = 0
for d in [2, 3]:
  while m % (n * d) == 0:
    n *= d
    a += 1
if n != m:
  a = -1
print(a)