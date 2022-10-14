I,N,B=input,'NO','b'
def s():
 n,s,t,j=I(),I(),I(),0
 if s.count(B)!=t.count(B):return N
 for i,x in enumerate(s):
  if x!=B:
   while t[j]==B:j+=1
   if x!=t[j]or(x=='a'and i>j)or(x=='c'and i<j):return N
   j+=1
for _ in [0]*int(I()):print(s()or'YES')