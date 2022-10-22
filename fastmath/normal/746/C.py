s, x1, x2 = map(int, input().split())
t1, t2 = map(int, input().split())
p, d = map(int, input().split())

tp = abs(x1 - x2) * t2

if p != x1:
    v = False
else:
    v = True

tt = 0
while 1:
    if p == s:
        d = -1
    
    if p == 0:
        d = 1
        
    p += d
    tt += t1
    if p == x1:
        v = True
        
    if v and p == x2:
        break
print(min(tp, tt))