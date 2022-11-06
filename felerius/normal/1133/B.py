n, k = map(int, input().split())
counts = [0] * k
for i in map(int, input().split()):
    counts[i % k] += 1

c = counts[0] // 2
for i in range(1, k):
    if 2 * i >= k:
        break
    c += min(counts[i], counts[k - i])
if k % 2 == 0:
    c += counts[k // 2] // 2

print(2 * c)