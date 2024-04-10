R=lambda:list(map(int,input().split()))
b,q,i,m=R()
a=set(R())
c=0
for _ in range(99):
  if abs(b)>i: break
  if b not in a: c+=1
  b*=q
print(c if c<32 else'inf')