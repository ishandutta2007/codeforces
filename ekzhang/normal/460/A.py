N, M = (int(x) for x in raw_input().strip().split())

day = 1
while N > 0:
    N -= 1
    if day % M == 0:
        N += 1
    day += 1

print day - 1