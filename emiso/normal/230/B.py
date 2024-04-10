raw_input()
l = map(int, raw_input().split())

isp = [True] * 1000010

isp[0] = isp[1] = False
for i in xrange(2, 1001):
    if isp[i]:
        for j in xrange(i*i, 1000010, i):
            isp[j] = False


for x in l:
    sq = int(round(x ** 0.5))
    if sq**2 == x and isp[sq]:
        print "YES"
    else: print "NO"