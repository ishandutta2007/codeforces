n=int(input())
mv = 10**9
f = [0 for i in range(4)]
adj = [[i == j for j in range(4)] for i in range(4)]
w = [0 for i in range(4)]
for _ in range(n):
 a,v,b=map(int,input().split())
 a-=1
 b-=1
 if a!=b: mv = min(mv, v)
 f[a]^=1
 f[b]^=1
 w[a] += v
 adj[a][b] = adj[b][a] = True
for k in range(4):
 for i in range(4):
  for j in range(4):
   if adj[i][k] and adj[k][j]: adj[i][j] = True
if all(adj[0]) and all(f):
 print(sum(w) - mv)
else:
 print(max(sum(w[j] for j in range(4) if adj[i][j]) for i in range(4)))