a, b=map(int, raw_input().split())
l=[map(int, raw_input().split()) for i in xrange(a)]
if a&1:
    print a
else:
    while True:
        x=l[:len(l)/2]
        y=l[len(l)/2:][::-1]
        if x==y:
            l=x
        else:
            break
    print len(l)