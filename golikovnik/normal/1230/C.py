n, m = map(int, input().split())

if n != 7:
  print(m)
  exit()

graph = [set() for _ in range(n)]

for _ in range(m):
  u, v = [int(x) - 1 for x in input().split()]
  graph[u].add(v)
  graph[v].add(u)

answer = 0
for u in range(n):
  for v in range(n):
    if u == v:
      continue
    adj = u in graph[v]
    wo_v = graph[u] - set([v])
    wo_u = graph[v] - set([u])
    wo = m - len(graph[v]) - len(graph[u]) + adj
    answer = max(answer, adj + wo + len(wo_v | wo_u))

print(answer)