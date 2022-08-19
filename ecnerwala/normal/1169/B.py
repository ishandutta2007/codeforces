n,m=map(int,input().split())
a=[[*map(int,input().split())] for _ in range(m)]
try:
 for x in a[0]:
  p = next(p for p in a if x not in p)
  for y in p:next(0for p in a if x not in p and y not in p)
 a=1
except:
 a=0
print("YNEOS"[a::2])