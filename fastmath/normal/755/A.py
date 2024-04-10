import math


def check(n):
    q = int(math.sqrt(n))
    for i in range(2, q + 1):
        if not (n % i):
            return False
    return True


n = int(input())
for i in range(1, 1000):
    if not check(n * i + 1):
        print(i)
        break