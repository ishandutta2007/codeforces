s=input()
a=-1
for i in range(1,len(s)-1):
  for j in range(i+1,len(s)):
    x=int(s[:i])
    y=int(s[i:j])
    z=int(s[j:])
    if s[0]=='0' and len(s[:i])>1:
      continue
    if s[i]=='0' and len(s[i:j])>1:
      continue
    if s[j]=='0' and len(s[j:])>1:
      continue
    if x>1e6 or y>1e6 or z>1e6:
      continue
    a=max(a,x+y+z)
print(a)