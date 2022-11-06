from collections import defaultdict
from itertools import groupby
n, k = map(int, input().split())
s = input()
counts = defaultdict(int)
for c, g in groupby(s):
    counts[c] += sum(1 for _ in g) // k
print(max(counts.values()))