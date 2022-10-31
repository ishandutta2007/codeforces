import math
R=lambda:list(map(int,input().split()))
a,b=R()
c,d=R()
if abs(b-d)%math.gcd(a,c)!=0:
  print(-1)
  exit(0)
while b != d:
  if b<d: b+=a
  else: d+=c
print(b)