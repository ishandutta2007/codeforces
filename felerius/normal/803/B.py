n = int(input())
a = list(map(int, input().split()))

dist = [n] * n
d = n
for i in range(n):
    if a[i] == 0:
        d = 0
    else:
        d += 1
    dist[i] = d
d = n
for i in reversed(range(n)):
    if a[i] == 0:
        d = 0
    else:
        d += 1
    if d is not None:
        dist[i] = min(dist[i], d)
print(' '.join(map(str, dist)))