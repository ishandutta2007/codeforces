import sys
i=input
n=int(i())
s=[*i()]
t=i()
if sorted(s)!=sorted(t):
 print(-1)
 sys.exit()
r=[]
for i in range(n):
 for j in range(i,n):
  if s[j]==t[i]:
   s[i:j+1]=s[j:j+1]+s[i:j]
   r.extend(range(j,i,-1))
   break
print(len(r))
print(*r)