n=int(input())%6
x=int(input())
for i in range(n,0,-1):
  if i%2 == 1 and x < 2:
    x = 1 - x
  elif i%2 == 0 and x > 0:
    x = 3 - x
print(x)