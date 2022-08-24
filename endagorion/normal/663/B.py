def f(s):
    if s == '':
        return 1988
    low = f(s[1:])
    l = -1
    r = 10 ** 18
    while r - l > 1:
        m = (l + r) / 2
        y = int(str(m) + s)
        if y > low and not (s[0] == '0' and m == 0):
            r = m
        else:
            l = m
    return int(str(r) + s)
    

n = int(raw_input())
for i in xrange(n):
    print(f(raw_input()[4:]))