input()
s=input()
x=set()
a=0
l=len(s)
for i in range(0,l):
  for j in range(i,l):
    ss=s[i:j+1]
    if any(chr(i) in ss for i in range(65, 91)):
      continue
    a=max(a,len(set(ss)))
print(a)