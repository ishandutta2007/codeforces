tux = input()
foo = bar = baz = 0
quz = 1
while tux > 0:
    pur = input()
    foo += pur
    bar += 1
    if max(foo * quz, bar * baz) == foo * quz:
        baz = foo
        quz = bar
    tux -= 1
print 1.0 * baz / quz