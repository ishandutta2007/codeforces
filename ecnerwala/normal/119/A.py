from math import gcd
def g():
 a,b,n=map(int,input().split())
 while 1:
  if n<1:return 1
  n -= gcd(a,n)
  if n<1:return 0
  n -= gcd(b,n)
print(g())