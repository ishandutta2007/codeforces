n = int(input())
if n < 3:
  print("NO")
  exit(0)
a = [int(i) - 1 for i in input().split()]
for i, x in enumerate(a):
  if i == a[a[x]]:
    print("YES")
    break
else:
  print("NO")