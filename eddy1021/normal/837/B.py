n,m=list(map(int,input().split()))
f=[input() for _ in range(n)]
def clr(ss):
    cc = None
    for s in ss:
        for c in s:
            if cc is None:
                cc = c
            elif cc != c:
                return None
    return cc
if n%3 == 0:
    s = set()
    for i in range(0,n,n//3):
        ret = clr(f[i:i+n//3])
        if ret is None:
            continue
        s.add(ret)
    if len(s) == 3:
        print('YES')
        exit(0)
if m%3 == 0:
    s = set()
    for j in range(0,m,m//3):
        ff = []
        for i in f:
            ff.append(i[j:j+m//3])
        ret = clr(ff)
        if ret is None:
            continue
        s.add(ret)
    if len(s) == 3:
        print('YES')
        exit(0)
print('NO')