k, a, b, v=map(int, raw_input().split())
maxdiv=k-1
boxes=0
while b>=maxdiv and a>0:
    a-=v*k
    b-=maxdiv
    boxes+=1
if a>0:
    if b<maxdiv:
        a-=v*(b+1)
        boxes+=1
    while a>0:
        a-=v
        boxes+=1
print boxes