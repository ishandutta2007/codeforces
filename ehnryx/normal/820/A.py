
# Problem A - July 27, 2017

x = raw_input().split()
c, v0, v1, a, l = int(x[0]), int(x[1]), int(x[2]), int(x[3]), int(x[4])

day = 0

while c > 0:

    day += 1

    if day != 1:
        c += l

    c -= v0

    v0 = min((v0 + a, v1))

print day