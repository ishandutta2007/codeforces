n, m = list(map(int,input().split()))
p = [ [ i for i in range(n) ] for j in range(m)]
def f(ci,xi):
  if xi==p[ci][xi]: return xi
  p[ci][xi] = f(ci,p[ci][xi])
  return p[ci][xi]
def uni(ci,xi,yi):
  p[ci][f(ci,xi)]=f(ci,yi)
for i in range(m):
  a, b, c = list(map(int,input().split()))
  uni(c-1,a-1,b-1)
for i in range(int(input())):
  a, b = list(map(int,input().split()))
  print(sum(1 if f(i,a-1) == f(i,b-1) else 0 for i in range(m)))