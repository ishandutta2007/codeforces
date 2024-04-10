n=input()
w=map(int, raw_input().split())
c=[]
for i in xrange(len(w)):
    while w[i]:
        c.append('P')
        w[i]-=1
        if w[i]:
            if i==len(w)-1:
                c.append('L')
                c.append('R')
            else:
                c.append('R')
                c.append('L')
    if i!=len(w)-1:
        c.append('R')
print "".join(c)