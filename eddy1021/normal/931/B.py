n,a,b=list(map(int,input().split()))
a-=1
b-=1
x=0
while n>2:
  a//=2
  b//=2
  n//=2
  x+=1
  if a==b:
    print(x)
    break
else:
  print('Final!')