n=int(input())
a=[*map(int,input().split())]
r,x,y=0,0,0
i,j=0,n
while i<=j:
  if x==y:
    r=x
    if i<n: x += a[i]
    i+=1
    j -=1
    y += a[j]
  elif x < y:
    if i<n: x+=a[i]
    i += 1
  else:
    j -= 1
    y+=a[j]
print(r)