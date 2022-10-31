R=lambda:list(map(int,input().split()))
R()
a=R()
b=R()
c=[x for x in a if x in b]
if len(c)>0:
  print(min(c))
else:
  a=min(a)
  b=min(b)
  if a>b: a,b=b,a
  print(a*10+b)