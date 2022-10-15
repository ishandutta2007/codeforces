n, x = map(int, raw_input().split())
bestmoments = [map(int, raw_input().split()) for _ in xrange(n)]

def fastestTime(t):
    """get fastest moves to go past time"""
    return divmod(t, x)[1]

time = fastestTime(bestmoments[0][0] - 1
                   ) + bestmoments[0][1] - bestmoments[0][0] + 1
prev = bestmoments[0][1]

for start, end in bestmoments[1:]:
    time += fastestTime(start - prev - 1)
    time += end - start + 1
    prev = end

print time