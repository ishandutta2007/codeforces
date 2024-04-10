v=[1,0,0,0,1,0,1,0,2,1,1,2,0,1,0,0]
n=int(input())
a=1 if n==0 else 0
while n>0:
  a+=v[n%16]
  n//=16
print(a)