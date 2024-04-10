from sys import stdin, stdout, stderr
from collections import deque

# Dinic class
INF = 0x3f3f3f3f
class Dinic:
  def __init__(self, N):
    self.N = N
    self.e = 0
    self.cap = []
    self.flow = []
    self.eid = []
    self.adj = [[] for i in range(N)]
  def add_edge(self, a, b, c, i = -1):
    self.adj[a].append((b,self.e))
    self.cap.append(c)
    self.flow.append(0)
    self.eid.append(i)
    self.e += 1
    self.adj[b].append((a,self.e))
    self.cap.append(0)
    self.flow.append(0)
    self.eid.append(i)
    self.e += 1
  def bfs(self, s, t):
    self.L = [INF for i in range(self.N)]
    self.nxte = [0 for i in range(self.N)]
    q = deque()
    q.append(s)
    self.L[s] = 0
    while q:
      u = q.pop()
      for v,e in self.adj[u]:
        if self.flow[e] < self.cap[e] and self.L[v] == INF:
          q.append(v)
          self.L[v] = self.L[u] + 1
    return self.L[t] < INF
  def dfs(self, u, t, f):
    if u == t: return f
    pushed = 0
    lim = len(self.adj[u])
    while self.nxte[u] < lim:
      v,e = self.adj[u][self.nxte[u]]
      if self.flow[e] < self.cap[e] and self.L[v] == self.L[u] + 1:
        cur = self.dfs(v, t, min(self.cap[e]-self.flow[e], f-pushed))
        self.flow[e] += cur
        self.flow[e^1] -= cur
        pushed += cur
      if pushed == f: break
      self.nxte[u] += 1
    return pushed
  def maxflow(self, s, t):
    ans = 0
    while self.bfs(s, t):
      ans += self.dfs(s, t, INF)
    return ans

# code here

n,m = map(int,stdin.readline().split())
ai = [int(x) for x in stdin.readline().split()]
bi = [int(x) for x in stdin.readline().split()]

graph = Dinic(2*n+2)
s,t = 0, 2*n+1

for i in range(m):
  a,b = map(int,stdin.readline().split())
  graph.add_edge(a, n+b, INF)
  graph.add_edge(b, n+a, INF)
for i in range(n):
  graph.add_edge(s, i+1, ai[i])
  graph.add_edge(n+i+1, t, bi[i])
  graph.add_edge(i+1, n+i+1, INF)

ans = graph.maxflow(s, t)

if ans != sum(ai) or ans != sum(bi):
  stdout.write('NO\n')
else:
  stdout.write('YES\n')
  grid = [[0 for j in range(n)] for i in range(n)]
  for u in range(1,n+1):
    for v,e in graph.adj[u]:
      if graph.flow[e] > 0 and 1 <= v-n and v-n <= n:
        grid[u-1][v-n-1] += graph.flow[e]
  stdout.write('\n'.join([' '.join([str(x) for x in line]) for line in grid]) + '\n')