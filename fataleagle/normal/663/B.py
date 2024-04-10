for _ in xrange(int(raw_input())):
    s = raw_input()[4:]
    year = 1988
    for i in xrange(len(s) - 1, -1, -1):
        suf = s[i:]
        l = len(suf)
        year += 10 ** (l - 1)
        while not str(year).endswith(suf):
            year += 10 ** (l - 1)
    print year