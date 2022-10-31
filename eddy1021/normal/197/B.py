import math
R=lambda:list(map(int,input().split()))
n,m=R()
a=R()[0]
b=R()[0]
if n>m: print(('-'if a*b<0 else'')+'Infinity')
elif n<m: print('0/1')
else:
  g=math.gcd(abs(a),abs(b))
  a//=g
  b//=g
  if b<0:a,b=-a,-b
  print(str(a)+'/'+str(b))