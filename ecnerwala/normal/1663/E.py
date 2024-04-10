from collections import defaultdict
n = int(input())
g = [input() for _ in range(n)]
strs = defaultdict(list)
for i in range(n):
    for j in range(n):
        strs[(0, i)].append(g[i][j])
        strs[(1, j)].append(g[i][j])
        strs[(2, i+j)].append(g[i][j])
        strs[(3, i-j)].append(g[i][j])
good = any('theseus' in s or 'theseus' in s for s in map(''.join, strs.values()))
print('YES' if good else 'NO')