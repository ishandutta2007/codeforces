for _ in range(int(input())):
    n = int(input())
    result = n * (n + 1) // 2
    p = 1
    while p <= n:
        result -= 2 * p
        p *= 2
    print(result)