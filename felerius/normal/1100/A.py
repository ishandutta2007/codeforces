n, k = (int(s) for s in input().split(' '))
tabs = [int(s) for s in input().split(' ')]
sums = [0] * k
for i, t in enumerate(tabs):
    sums[i % k] += t
total_sum = sum(sums)
print(max(abs(total_sum - s) for s in sums))