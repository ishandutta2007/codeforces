input()
a=0
b=0
c=0
d=dict()
e=dict()
for i in list(map(int,input().split())):
  x,y=0,0
  for j in range(i-1,i+2):
    if j in d:
      x+=d[j]
      y+=e[j]
  a+=(c-y)*i-b+x
  b+=i
  c+=1
  d[i]=i if i not in d else d[i]+i
  e[i]=1 if i not in e else e[i]+1
print(a)