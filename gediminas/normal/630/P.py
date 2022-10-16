import math
from functools import reduce
'''input
7 10
'''

n, r=[int(x) for x in input().split()]

A = math.radians(90) / n
B = math.radians(180) / n
C = math.pi - A - B

c = r / math.sin(C) * math.sin(A)

print(r*c * math.sin(B) * n)