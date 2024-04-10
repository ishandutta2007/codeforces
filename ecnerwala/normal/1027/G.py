from math import gcd
def powmod(a,b,m):
 a%=m
 r=1
 while b:
  if b&1:r=r*a%m
  a=a*a%m
  b>>=1
 return r

def f(n):
 r=[]
 if (n&1)==0:
  e=0
  while (n&1)==0:n>>=1;e+=1
  yield (2,e)
 p=3
 while n>1:
  if p*p>n:p=n
  if n%p:
   p+=2
   continue
  e=1;n//=p
  while n%p==0:n//=p;e+=1
  yield (p,e)
  p+=2
 return r
m,x=map(int,input().split())
p=2
r=[(1,1)]
for p,e in f(m):
 assert e>=1
 ord=p-1
 assert powmod(x,ord,p)==1
 for pi,ei in f(p-1):
  while ord % pi == 0 and powmod(x,ord//pi,p)==1: ord//=pi
 ords=[(1,1),(ord,p-1)]
 q=p
 for v in range(2,e+1):
  q*=p
  if powmod(x,ord,q)!=1:ord*=p
  assert powmod(x,ord,q)==1
  ords.append((ord,q//p*(p-1)))
 r=[(a//gcd(a,c)*c,b*d) for a,b in r for c,d in ords]
print(sum(y//x for x,y in r))