from sys import stdin
lines = [int(x) for x in stdin.readlines()[::-1]]

for x in lines:
    if x < 0:
        ares = (-x)**.5
    else:
        ares = x**.5
    res = ares + x**3*5

    if res >= 400:
        print("f(%d) = MAGNA NIMIS!" % x)
    else:
        print("f(%d) = %.2f" % (x,res))