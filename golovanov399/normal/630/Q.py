from math import sqrt, sin, cos, pi

a, b, c = map(int, raw_input().split())
print 1.0 / 3 * (0.5 * a ** 2 * sin(pi / 3) * a * sqrt(2.0 / 3) + 
    b * b * b / sqrt(2) + 5 * c * 0.5 * c * 0.5 * sin(3 * pi / 10) / cos(3 * pi / 10) * sqrt(c ** 2 - (c * 0.5 / cos(3 * pi / 10)) ** 2))