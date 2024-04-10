q = int(input())
for u in range(q):
    n = int(input())
    k = n
    i = n
    while(True):
        s = 0
        while(n > 0):
            a = n % 3
            n = n // 3
            if a > 1:
                s = 1
                break
        if s == 0:
            print()
            print(i)
            break
        i += 1
        n = i