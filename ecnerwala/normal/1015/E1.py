n,m=map(int,input().split())
g=[[*input()] for _ in range(n)]
c=[[0 for _ in range(m)] for _ in range(n)]
for i in range(n):
 v=0
 for j in range(m):
  v=(v+1)*(g[i][j]=='*')
  c[i][j]=v
 v=0
 for j in range(m-1,-1,-1):
  v=(v+1)*(g[i][j]=='*')
  c[i][j]=min(c[i][j],v)
for j in range(m):
 v=0
 for i in range(n):
  v=(v+1)*(g[i][j]=='*')
  c[i][j]=min(c[i][j],v)
 v=0
 for i in range(n-1,-1,-1):
  v=(v+1)*(g[i][j]=='*')
  c[i][j]=min(c[i][j],v)
for i in range(n):
 for j in range(m):
  if c[i][j]==1: c[i][j]=0
for i in range(n):
 v=0
 for j in range(m):
  v=max(v-1,c[i][j])
  if v:g[i][j]='.'
 v=0
 for j in range(m-1,-1,-1):
  v=max(v-1,c[i][j])
  if v:g[i][j]='.'
for j in range(m):
 v=0
 for i in range(n):
  v=max(v-1,c[i][j])
  if v:g[i][j]='.'
 for i in range(n-1,-1,-1):
  v=max(v-1,c[i][j])
  if v:g[i][j]='.'
if all(g[i][j]=='.' for i in range(n) for j in range(m)):
 r=[(i+1,j+1,c[i][j]-1) for i in range(n) for j in range(m) if c[i][j]]
 print(len(r))
 for t in r: print(*t)
else:
 print(-1)