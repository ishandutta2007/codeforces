px, py, vx, vy, a, b, c, d = map(int, raw_input().split())
from math import *
D = sqrt(vx ** 2 + vy ** 2)
vx *= b / D
vy *= b / D
print px + vx, py + vy
print px - vy * 0.5 * a / b, py + vx * 0.5 * a / b
print px - vy * 0.5 * c / b, py + vx * 0.5 * c / b
print px - vy * 0.5 * c / b - vx * d / b, py + vx * 0.5 * c / b - vy * d / b
print px + vy * 0.5 * c / b - vx * d / b, py - vx * 0.5 * c / b - vy * d / b
print px + vy * 0.5 * c / b, py - vx * 0.5 * c / b
print px + vy * 0.5 * a / b, py - vx * 0.5 * a / b