n, k = map(int, input().split(' '))
deg = [0] * n
neighbors = [[] for i in range(n)]
edges = []
for i in range(n - 1):
    a, b = map(int, input().split(' '))
    neighbors[a - 1].append(b - 1)
    neighbors[b - 1].append(a - 1)
    deg[a - 1] += 1
    deg[b - 1] += 1
    edges.append((a - 1, b - 1))

deg = list(sorted(deg))
r = deg[-(k + 1)]
print(r)

from collections import deque
colors = {}
q = deque()
q.append((None, 0))
while q:
    par, node = q.popleft()
    parcolor = None if par is None else colors[(par, node)]
    color = 0 if parcolor != 0 else 1
    deg = len(neighbors[node])
    for neigh in neighbors[node]:
        if neigh != par:
            if deg > r:
                colors[(node, neigh)] = 0 if parcolor is None else parcolor
            else:
                colors[(node, neigh)] = color
                color += 1
                if color == parcolor:
                    color += 1
            q.append((node, neigh))

for a, b in edges:
    if (a, b) in colors:
        print(colors[(a, b)] + 1, end=' ')
    else:
        print(colors[(b, a)] + 1, end=' ')