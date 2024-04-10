from collections import Counter

n = int(input())
a = list(map(int, input().split()))
result, count = 0, Counter()
for i in range(n):
    result += (2 * i - n + 1) * a[i] - count[a[i] - 1] + count[a[i] + 1]
    count[a[i]] += 1
print(result)