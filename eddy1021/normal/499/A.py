n, x = list(map(int,input().split()))
c, a = 0, 0
for i in range(n):
  l, r = list(map(int,input().split()))
  while c + x < l: c += x
  a, c = a + r - c, r
print(a)