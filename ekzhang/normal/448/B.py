def isAnagram(s1, s2):
    if sorted(s1) == sorted(s2):
        return True
    return False

def removable(s1, s2):
    if len(s1) <= len(s2):
        return False
    assert len(s1) > len(s2)

    c2 = 0
    for c1 in xrange(len(s1)):
        if s1[c1] == s2[c2]:
            c2 += 1
        if c2 == len(s2):
            return True
    return False

s1 = raw_input().strip()
s2 = raw_input().strip()

if isAnagram(s1, s2):
    print 'array'
elif removable(s1, s2):
    print 'automaton'
elif removable(sorted(s1), sorted(s2)):
    print 'both'
else:
    print 'need tree'