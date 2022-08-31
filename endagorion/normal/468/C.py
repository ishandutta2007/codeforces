def f(s):
    N = 0
    p = 0
    L = len(s)
    for i in xrange(len(s)):
        k = L - i - 1
        for j in xrange(int(s[i])):
            N += 9 * k * (10 ** k) / 2
            N += (p + j) * (10 ** k)
        p += int(s[i])
    return N

def g(N):
    if N == 0:
        return '0'
    s = ''
    L = 20
    for i in xrange(L):
        d = 0
        for j in xrange(10):
            if f(s + str(j) + ('0' * (L - i - 1))) >= N:
                s = s + str(j - 1)
                d = 1
                break
        if not d:
            s = s + str(9)
        #print s
    return s

A = input()
s = []
p = []
i = 1
while 1:
    m = g(i * A)
    q = f(m) % A
    d = 0
#    print m, q
    for i in xrange(len(p)):
        if q == p[i] and int(m) > int(s[i]):
            print int(s[i]), int(m) - 1
            d = 1
            break
    if d:
        break
    s.append(m)
    p.append(f(m) % A)
    i += 1