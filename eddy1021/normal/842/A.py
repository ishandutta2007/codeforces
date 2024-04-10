l,r,x,y,k=list(map(int,input().split()))
print('YES'if max(l//k+(1 if l%k>0 else 0),x)<=min(r//k,y) else'NO')