a,b=list(map(int,input().split()))
ans=0
while a<=b:
  ans+=1
  a,b=a*3,b*2
print(ans)