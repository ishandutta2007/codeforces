R=lambda:list(map(int,input().split()))
n,m=R()
def cal(c,u,v):
  r=0
  for i in range(u):
    d=sum(c[i])
    r+=(1<<d)-1
    r+=(1<<(v-d))-1
  return r
a=[R() for i in range(n)]
b=[[a[i][j] for i in range(n)] for j in range(m)]
print(cal(a,n,m)+cal(b,m,n)-n*m)