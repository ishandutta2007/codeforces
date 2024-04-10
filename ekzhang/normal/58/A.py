def removable(s1, s2):
    if len(s1) < len(s2):
        return False

    c2 = 0
    for c1 in xrange(len(s1)):
        if s1[c1] == s2[c2]:
            c2 += 1
        if c2 == len(s2):
            return True
    return False

S = raw_input()
if removable(S, 'hello'):
    print 'YES'
else:
    print 'NO'