from collections import deque
n = int(input())
adj = [[] for _ in range(n)]
for _ in range(n - 1):
    u, v, c = map(int, input().split())
    adj[u].append((v, c))
    adj[v].append((u, c))
dist = [10**9] * n
dist[0] = 0
q = deque()
q.append((0, n))
while q:
    i, p = q.popleft()
    for i2, c in adj[i]:
        if i2 == p:
            continue
        dist[i2] = dist[i] + c
        q.append((i2, i))
print(max(dist))