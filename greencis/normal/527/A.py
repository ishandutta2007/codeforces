a,b=map(int,input().split())
ans=0
while a and b:
 if a>b:
  ans += a // b
  a %= b
 else:
  ans += b // a
  b %= a
print(ans)