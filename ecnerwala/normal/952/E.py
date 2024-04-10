n = int(input())
a, b = 0,0 
for _ in range(n):
  t,s = input().split()
  if s == 'hard': a += 1
  else: b += 1
a,b = sorted([a,b])
res = int((n-1) ** 0.5)
while True:
  s = res * res
  if s // 2 >= a and s - s // 2 >= b:
    break
  res += 1
print(res)