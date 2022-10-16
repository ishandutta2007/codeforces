seq = []
for x in range(11): seq.append(int(input()))

p = 0
while seq:
    c = seq[-1]
    del seq[-1]

    r = abs(c)**0.5 + c**3 * 5
    if r < 400:
        print("f(%d) = %.2f" % (c, r))
    else:
        print("f(%d) = MAGNA NIMIS!" % c)