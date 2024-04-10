a, b, c = map(float, raw_input().split())
D = b ** 2 - 4 * a * c
if a < 0:
    a, b, c = -a, -b, -c
from math import sqrt
print "%8f\n%8f" % ((-b + sqrt(D)) / 2 / a, (-b - sqrt(D)) / 2 / a)