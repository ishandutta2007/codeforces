n,t=map(int,input().split())
s=input()
for i in range(t):
  a=list(s)
  for i in range(n-1):
    if s[i:i+2]=='BG':
     a[i:i+2]=['G','B']
  s=''.join(a)
print(s)