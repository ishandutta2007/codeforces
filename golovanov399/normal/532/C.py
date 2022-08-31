#!/usr/bin/python

a = list(map(int, raw_input().split()))

x, y, X, Y = a[0], a[1], a[2], a[3]

if x <= X and y <= Y:
    print "Polycarp"
elif x >= X and y >= Y:
    print "Vasiliy"
else:
    if X < Y:
        x, y, X, Y = y, x, Y, X
    if X <= x:
        print "Vasiliy"
    else:
        t1 = y
        t2 = X - x
        if t1 <= t2:
            print "Polycarp"
        else:
            print "Vasiliy"