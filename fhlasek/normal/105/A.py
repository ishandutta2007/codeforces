
a=raw_input().strip().split()
n=int(a[0])
m=int(a[1])
k=float(a[2])
res=[]
tmp=[]

def trans(x):
  y=int(k*x+0.0001)
  if(y<100): return -1
  return y

for i in range(n):
  l=raw_input().strip().split()
  if(trans(int(l[1]))!=-1):
    tmp.append(l[0])
    res.append((l[0],trans(int(l[1]))))

for i in range(m):
  l=raw_input().strip()
  if l not in tmp: res.append((l,0))

res.sort()
print len(res)
for i in res:
  print i[0],i[1]