n,m=list(map(int,input().split()))
a={}
for i in range(n):
  x,y=input().split()
  a[y]=x
for i in range(m):
  s=input()
  print(s,'#'+a[s.split()[1][:-1]])