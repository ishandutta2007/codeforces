h,m=list(map(int,input().split(':')))
a=0
while h//10!=m%10 or h%10!=m//10:
  a+=1
  m+=1
  if m>=60: h+=1
  h%=24
  m%=60
print(a)