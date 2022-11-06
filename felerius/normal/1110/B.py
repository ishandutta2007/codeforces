n, m, k = map(int, input().split())
b = list(map(int, input().split()))
if k == 1:
    print(b[-1] - b[0] + 1)
else:
    dists = list(sorted(b[i] - b[i - 1] for i in range(1, len(b))))
    print(sum(dists[:-(k - 1)]) + k)