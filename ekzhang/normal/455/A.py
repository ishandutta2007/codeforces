def getAns(ar):
    bestScores = [None] * 100000
    bestScores[-1] = 100000 * ar[-1]
    bestScores[-2] = max((bestScores[-1], 99999 * ar[-2]))
    bestScores[-3] = max((99998 * ar[-3] + bestScores[-1], bestScores[-2]))
    
    for i in xrange(99996, -1, -1):
        bestScores[i] = max(((i + 1) * ar[i] + bestScores[i + 2],
                             (i + 2) * ar[i + 1] + bestScores[i + 3]))
    
    return bestScores[0]

N = input()
ar = [0] * 100000
for i in (int(x) for x in raw_input().split()):
    ar[i - 1] += 1

print getAns(ar)