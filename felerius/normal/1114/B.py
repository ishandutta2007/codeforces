n, m, k = map(int, input().split())
a = list(map(int, input().split()))
ind = list(sorted(range(n), key=lambda i: a[i], reverse=True))
ind2 = list(sorted(ind[:m*k]))
print(sum(a[i] for i in ind2))
for i in range(k - 1):
    print(ind2[i*m + m - 1] + 1, end=' ')
print()