p,x,y=list(map(int,input().split()))
s=0
while 1>0:
  for sc in range(x,y-1,-50):
    i=(sc//50)%475
    for _ in range(25):
      i=(i*96+42)%475
      if 26+i==p:
        print(s)
        exit(0)
  s+=1
  x+=100