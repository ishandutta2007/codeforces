t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    c = 0
    while n > 0:
        if n % k == 0:
            n //= k
            c += 1
        else:
            m = n % k
            n -= m
            c += m
    print(c)