N, M = map(int, raw_input().split())
print N + M - 1
print 1, 1
for i in range(2, N+1):
    print i, 1
for i in range(2, M+1):
    print 1, i