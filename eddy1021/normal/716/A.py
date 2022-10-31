n, c = map(int,input().split())
t = map(int,input().split())
ans, pre = 0, 0
for x in t:
  if x - pre > c: ans = 0
  ans, pre = ans + 1, x
print( ans )