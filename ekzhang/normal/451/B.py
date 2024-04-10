N = input()
A = map(int, raw_input().split())

decreasing = None
increasing = None
done = False
for i, j in enumerate(A):
    if i == 0:
        continue
    if A[i - 1] > j:
        if not increasing:
            if not decreasing:
                decreasing = i
        else:
            print "no"
            done = True
            break

    else:
        if not increasing:
            if decreasing:
                increasing = i

if not done:
    if decreasing and increasing:
        if A[decreasing - 1] < A[increasing] and ((A[increasing - 1] > A[decreasing - 2]) or decreasing == 1):
            print 'yes'
            print decreasing, increasing
        else:
            print 'no'
    elif decreasing and not increasing:
        if (A[-1] > A[decreasing - 2]) or (decreasing == 1):
            print 'yes'
            print decreasing, len(A)
        else:
            print 'no'
    else: # not both
        print 'yes'
        print '1 1'