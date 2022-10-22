a, b = map(int, input().split())
c, d = map(int, input().split())

s1 = set()
s2 = set()
f = False
b -= a
d -= c
for i in range(10 ** 4):
    b += a
    s1.add(b)
    d += c
    s2.add(d)
    
    if (b in s2):
        print(b)
        f = True
        break
    
    if (d in s1):
        print(d)
        f = True
        break
    
if not f:
    print(-1)