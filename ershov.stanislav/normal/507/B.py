import math
r, x, y, x1, y1 = map(float, input().split())
print(int(math.ceil(math.sqrt((x - x1)**2 + (y - y1) ** 2) / 2 / r)))