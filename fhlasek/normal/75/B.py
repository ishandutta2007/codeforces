
me=raw_input().strip()
N=int(raw_input())
d={}
for i in range(N):
  l=raw_input()
  a=l.split()[0]
  b=l.split()[-2].split("'")[0]
  if(l.split()[1]=="posted"): act=15
  if(l.split()[1]=="commented"): act=10
  if(l.split()[1]=="likes"): act=5
  if(a!=me and a not in d.keys()): d[a]=0
  if(b!=me and b not in d.keys()): d[b]=0
  if(a==me): d[b]+=act
  if(b==me): d[a]+=act

p=[]
for i in d.keys(): p.append((1000000-d[i],i))
p.sort()
for i in p: print i[1]