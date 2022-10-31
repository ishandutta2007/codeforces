p,y=list(map(int,input().split()))
t=min(p,int(y**.5)+2)
for i in range(y,p,-1):
  while t*t>i:t-=1
  if not any(i%x==0 for x in range(2,t+1)):
    print(i)
    exit(0)
print(-1)