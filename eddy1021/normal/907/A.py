a,b,c,d=list(map(int,input().split()))
for i in range(0,300):
  for j in range(0,i):
    for k in range(d,j):
      if a<=i<=a+a and b<=j<=b+b and c<=k<=c+c and k<=d+d and j>d+d:
        print(str(i)+'\n'+str(j)+'\n'+str(k))
        exit(0)
print(-1)