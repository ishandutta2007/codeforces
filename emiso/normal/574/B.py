n, m = [int(x) for x in input().split()]

adj = [set() for i in range(n + 1)]
degree = [0 for i in range(n + 1)]
answer = 999999
edges = []

for i in range(m):
    u, v = [int(x) for x in input().split()]
    edges.append((u, v))

    adj[u].add(v)
    degree[u] += 1

    adj[v].add(u)
    degree[v] += 1

for e in edges:
    for w in adj[e[0]]:
        if w in adj[e[1]]:
            answer = min(answer, degree[w] + degree[e[0]] + degree[e[1]] - 6)

if answer == 999999: print(-1)
else: print(answer)