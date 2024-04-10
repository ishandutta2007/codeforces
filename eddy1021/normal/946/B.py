a,b=list(map(int,input().split()))
while a>0 and b>0:
  if a>=b+b:a%=b+b
  elif b>=a+a:b%=a+a
  else: break
print(a,b)