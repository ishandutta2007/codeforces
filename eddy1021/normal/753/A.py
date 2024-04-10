n = int(input())
ans = []
nxt = 1
while n > 0:
  x = nxt
  n -= nxt
  nxt += 1
  if n < nxt:
    x += n
    n = 0
  ans.append(str(x))
print(len(ans))
print(" ".join(ans))