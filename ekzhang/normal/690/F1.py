N = input()
A = [0 for _ in range(N)]
for i in range(N - 1):
    a, b = map(int, raw_input().split())
    A[a - 1] += 1
    A[b - 1] += 1

print sum(x * (x - 1) / 2 for x in A)