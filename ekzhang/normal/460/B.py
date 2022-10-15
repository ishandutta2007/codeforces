BOUND = 10 ** 9

def digitsum(n):
    return sum(int(x) for x in str(n))

def getAns(a, b, c, bound=BOUND):
    ans = [] # list of answers
    for dsum in xrange(1, 82):
        solution = b * (dsum ** a) + c
        if 0 < solution < bound and digitsum(solution) == dsum:
            ans.append(solution)
    return sorted(ans)

A, B, C = (int(x) for x in raw_input().strip().split())

ans = getAns(A, B, C)
print len(ans)
if ans:
    print ' '.join(str(x) for x in ans)