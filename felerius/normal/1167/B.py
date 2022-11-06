import itertools
import sys

a = [4, 8, 15, 16, 23, 42]
m = {}
queries = [(0, 1), (1, 2), (2, 3), (3, 4)]

for perm in itertools.permutations(a):
    t = tuple(perm[i] * perm[j] for i, j in queries)
    m[t] = perm

l = []
for a, b in queries:
    print(f'? {a + 1} {b + 1}')
    sys.stdout.flush()
    l.append(int(input()))

p = m[tuple(l)]
print('! ' + ' '.join(map(str, p)))