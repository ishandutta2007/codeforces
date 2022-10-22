import math

a, b = map(int, input().split())
n = int(input())
ans = 10 ** 9
for i in range(n):
    x, y, v = map(int, input().split())
    ans = min(ans, math.sqrt(abs(a - x) * abs(a - x) + abs(b - y) * abs(b - y)) / v)
print(ans)