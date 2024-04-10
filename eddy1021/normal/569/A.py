t, s, q = list(map(int,input().split()))
a = 0
while s < t:
  s *= q
  a += 1
print(a)