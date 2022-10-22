import math

n = int(input())

for i in range(1, int(math.sqrt(n)) + 1):
    if not (n % i):
        ans = [i, n // i]

print(ans[0], ans[1])