from collections import Counter

n = int(input())
arr = [int(i) for i in input().split()]
cnt = Counter()
for i in arr:
    cnt[i] += 1
cur = Counter()
s = sum(arr)
d = 0
i = 0
for val in arr:
    n1 = cnt[val - 1] - cur[val - 1]
    n2 = cnt[val + 1] - cur[val + 1]
    n3 = cnt[val] - cur[val]
    d += s - (n - i) * val
    d -= n1 * (val - 1)
    d += n1 * val
    d -= n2 * (val + 1)
    d += n2 * val
    d -= n3 * val
    d += n3 * val
    i += 1
    s -= val
    cur[val] += 1
print(d)