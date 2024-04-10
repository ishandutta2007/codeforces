n = int(input())
nc = 0
a = [0] * n
for i in range(n):
    a[i] = int(input())
    if a[i] % 2 == 0:
        print(a[i] // 2)
    else:
        nc = (nc + 1) % 2
        if nc == 1:
            print(a[i] // 2)
        else:
            print((a[i] + 1) // 2)