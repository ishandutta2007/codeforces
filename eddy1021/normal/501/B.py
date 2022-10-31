n, d = int(input()), dict()
for i in range(n):
  a, b = input().split()
  tag = False
  for i in d:
    if d[i] == a:
      d[i] = b
      tag = True
      break
  if not tag: d[a] = b
print(len(d))
for i in d:
  print(i, d[i])