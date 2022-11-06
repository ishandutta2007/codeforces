from collections import defaultdict
n, k = (int(s) for s in input().split(' '))
a = [int(s) for s in input().split(' ')]
counts = defaultdict(int)
for i in a:
    counts[i] += 1
    
if k > n or any(c > k for c in counts.values()):
    print('NO')
else:
    print('YES')
    coloring = []
    used = set()
    for i in range(k):
        coloring.append(i + 1)
        used.add((i + 1, a[i]))
    for i in a[k:]:
        while (counts[i], i) in used:
            counts[i] -= 1
        coloring.append(counts[i])
        counts[i] -= 1
    print(' '.join(str(i) for i in coloring))