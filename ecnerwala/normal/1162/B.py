i=lambda:[*map(int,input().split())]
n,m=i()
a,b=[[i()for _ in range(n)]for _ in[0,1]]
for x in range(n):
 for y in range(m):
  if a[x][y] > b[x][y]:a[x][y], b[x][y] = b[x][y], a[x][y]
def g(c):
 for x in range(n-1):
  for y in range(m):
   if c[x][y] >= c[x+1][y]: return 1
 for x in range(n):
  for y in range(m-1):
   if c[x][y] >= c[x][y+1]: return 1
 return 0
print(('Imp'if(g(a)|g(b))else'P')+'ossible')