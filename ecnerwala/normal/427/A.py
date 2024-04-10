n = int(input())
r = 0
v = 0
for a in map(int, input().split()):
  if a == -1:
    if v == 0: r += 1
    else: v -= 1
  else: v += a

print(r)