n = int(input())
a = []
used = [[False] * n for _ in range(n)]
for _ in range(n):
  a.append(input())
let = None
for i in range(n):
  if a[i][i] != a[n - i - 1][i]:
    print("NO")
    exit(0)
  used[i][i] = used[n - i - 1][i] = True
  if let is None:
    let = a[i][i]
  elif a[i][i] != let:
    print("NO")
    exit(0)
let2 = None
for i in range(n):
  for j in range(n):
    if used[i][j]:
      continue
    if a[i][j] == let:
      print("NO")
      exit(0)
    used[i][j] = True
    if let2 is None:
      let2 = a[i][j]
    elif a[i][j] != let2:
      print("NO")
      exit(0)
print("YES")