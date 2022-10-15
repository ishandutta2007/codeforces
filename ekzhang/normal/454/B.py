from collections import deque

def isPossible(li):
    increasing = True
    index = None
    for i in xrange(len(li) - 1):
        if li[i] > li[i + 1]:
            if increasing:
                increasing = False
                index = i
            else:
                return False, None
    if increasing:
        return True, len(li) - 1
    return li[0] >= li[-1], index

N = input()
L = map(int, raw_input().split())

li = deque(L)

x = isPossible(li)
if not x[0]:
    print '-1'

else:
    print N - x[1] - 1