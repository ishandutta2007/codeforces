cache=[None]*101**3
solve=lambda r, p, s: cache[r*101*101+p*101+s]
for r in xrange(101):
    for p in xrange(101):
        for s in xrange(101):
            key=r*101*101+p*101+s
            if (r==0)+(p==0)+(s==0)==2:
                cache[key]=(float(r!=0), float(p!=0), float(s!=0))
            else:
                allpairs=r*s+r*p+s*p
                a=[]
                if r and s:
                    a.append(map((float(r*s)/allpairs).__mul__, solve(r, p, s-1)))
                if r and p:
                    a.append(map((float(r*p)/allpairs).__mul__, solve(r-1, p, s)))
                if s and p:
                    a.append(map((float(s*p)/allpairs).__mul__, solve(r, p-1, s)))
                cache[key]=tuple(sum(i) for i in zip(*a))
r, s, p=map(int, raw_input().split())
r, p, s=solve(r, p, s)
print r, s, p