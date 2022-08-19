n,c = map(int, input().split())
t = 0
b = 0
cnt = 0
for i in map(int, input().split()):
  if (i-t) > c: cnt = 1
  else: cnt += 1
  t = i
  b = max(b, cnt)
print(cnt)