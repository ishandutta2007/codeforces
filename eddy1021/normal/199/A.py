n=int(input())
x,y=0,1
while x+y<n:
  x,y=y,x+y
print(0,x,min(n,y))