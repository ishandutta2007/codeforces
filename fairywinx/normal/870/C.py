q = int(input())
for i in range(q):
    n = int(input())
    if n == 1 or n == 2 or n == 3 or n == 5 or n == 7 or n == 11:
        print(-1)
    elif n % 2 == 0:
        print(n // 4)
    elif n % 4 == 1:
        print(n // 4 - 1)
    else:
        print((n - 15) // 4 + 2)