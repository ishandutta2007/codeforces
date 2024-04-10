l=sorted([(len(raw_input())-2, chr(i+ord('A'))) for i in xrange(4)])
a=l[0][0]*2<=l[1][0]
b=l[2][0]*2<=l[3][0]
if a^b:
    if l[0][0]*2<=l[1][0]:
        print l[0][1]
    else:
        print l[3][1]
else:
    print 'C'