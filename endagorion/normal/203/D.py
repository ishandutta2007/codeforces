import math

def new_line():
    return [int(x) for x in raw_input().split()]

a, b, m = new_line()
vx, vy, vz = new_line()
t = 1.0 * m / (-vy)
xx = 0.5 * a + t * vx
zz = t * vz
xi = int(math.floor(xx / a))
zi = int(math.floor(zz / b))
x = xx - xi * a
if xi % 2 == 1:
    x = a - x
z = zz - zi * b
if zi % 2 == 1:
    z = b - z
print x, z