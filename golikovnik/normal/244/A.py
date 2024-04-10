n, k = map(int, input().split())
res = [[] for _ in range(k)]
used = set()
for i, val in enumerate(input().split()):
    val = int(val)
    used.add(val)
    res[i].append(val)
i = 0
for val in range(1, n*k+1):
    if val in used:
        continue
    while len(res[i]) == n:
        i += 1
    res[i].append(val)
for i in res:
    print(*i)