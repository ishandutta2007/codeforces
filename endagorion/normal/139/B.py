import math

N = input()
l = [0] * N
w = [0] * N
h = [0] * N
for i in range(N):
    l[i], w[i], h[i] = [int(x) for x in raw_input().split()]

M = input()
L = [0] * M
W = [0] * M
C = [0] * M
for i in range(M):
    L[i], W[i], C[i] = [int(x) for x in raw_input().split()]

ans = 0
for i in range(N):
    cost = 10 ** 18
    d = 2 * (l[i] + w[i])
    for j in range(M):
        if L[j] < h[i]:
            continue
        k = int(math.ceil(1.0 * d / W[j]))
        c = L[j] / h[i]
        n = int(math.ceil(1.0 * k / c))
        cost = min(cost, n * C[j])
    ans = ans + cost

print ans