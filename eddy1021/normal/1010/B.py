import sys
def q(x):
  print(x)
  sys.stdout.flush()
  s=int(input())
  if s==0: exit(0)
  return s
m,n=list(map(int,input().split()))
f=[q(1)==1 for i in range(n)]
l,r,it=1,m,-1
while l<=r:
  it+=1
  md=(l+r)//2
  s=q(md)
  if (s==1)==f[it%n]: l=md+1
  else: r=md-1