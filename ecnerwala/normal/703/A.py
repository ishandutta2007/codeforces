n = int(input())
m, c = 0,0
for i in range(n):
  x,y = map(int, input().split())
  m += x > y
  c += y > x
if m == c: print("Friendship is magic!^^")
elif m > c: print("Mishka")
else: print("Chris")