c, v, v1, a, l = map(int, input().split())

for i in range(1, 1000000):
    c -= v
    
    if i > 1:
        c += l
        
    if c <= 0:
        print(i)
        break
    
    v += a
    v = min(v, v1)