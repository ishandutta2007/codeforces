import math
n, r = (int(s) for s in input().split(' '))
s = math.sin(math.pi / n)
print(-r * s / (s - 1))