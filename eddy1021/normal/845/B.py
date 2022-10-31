x=int(input())
def s(a):
  r=0
  while a>0:
    r+=a%10
    a//=10
  return r
def d(a,b):
  r=0
  for i in range(6):
    if a%10!=b%10:
      r += 1
    a//=10
    b//=10
  return r
c=6
for i in range(1000000):
  if s(i%1000)==s(i//1000):
    c=min(c,d(x,i))
print(c)