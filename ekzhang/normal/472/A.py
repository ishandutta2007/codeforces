def getAns(n):
    if n % 2 == 0:
        print 4, n - 4
    else:
        print 9, n - 9

N = input()
getAns(N)