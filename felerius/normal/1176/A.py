q = int(input())
for _ in range(q):
    n = int(input())
    c = 0
    while n > 1:
        c += 1
        if n % 2 == 0:
            n //= 2
        elif n % 3 == 0:
            n = (n // 3) * 2
        elif n % 5 == 0:
            n = (n // 5) * 4
        else:
            break
    if n == 1:
        print(c)
    else:
        print(-1)