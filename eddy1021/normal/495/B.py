a, b = list(map(int,input().split()))
if a == b:
  print("infinity")
  exit(0)
a, ans = a - b, 0
for i in range(1,a+1):
  if i * i > a: break
  if a % i != 0: continue
  if i > b: ans += 1
  if i != a // i and a // i > b: ans += 1
print(ans)