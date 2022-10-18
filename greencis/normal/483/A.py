import fractions
f=fractions.gcd
l,r=map(int,input().split())
for a in range(l,r+1):
 for b in range(a,r+1):
  for c in range(b,r+1):
   if f(a,b)==1 and f(b,c)==1 and f(a,c)!=1:
    print(a,b,c)
    exit()
print(-1)