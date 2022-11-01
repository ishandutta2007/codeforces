import sys
ans = ""
for i in range(4):
  bst, bsta = 0, -1
  for j in range(10):
    tans = ""
    for k in range(4):
      if i == k:
        tans += str(j)
      else:
        tans += "0"
    print(tans)
    sys.stdout.flush()
    a, b = list(map(int,input().split()))
    if a == 4 and b == 0:
      exit(0)
    if a > bsta:
      bst, bsta = j, a
  ans += str(bst)
print(ans)
sys.stdout.flush()