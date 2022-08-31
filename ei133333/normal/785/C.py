N, M = map(int, input().split())

if N <= M:
    print(N)
else:
    low = M + 1
    high = 1000000000000000000
    while high - low > 0:
        mid = (low + high) // 2
        if N + (mid - (M + 1)) * M - ((mid - M) * (M + 1 + mid) // 2) <= 0:
            high = mid
        else:
            low = mid + 1
    print(low)