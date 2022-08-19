input()
l=1000002
c=[1,1]+[0]*l
for i in range(2,l):
 if 1-c[i]:
  for j in range(i*i,l,i):c[j]=1
for i in input().split():
 i=int(i)
 r=int(i**0.5)
 print('YNEOS'[c[r]or r*r!=i::2])