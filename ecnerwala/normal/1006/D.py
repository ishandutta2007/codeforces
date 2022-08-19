n=int(input())
a,b=input(),input()
r=0
for i in range(n//2):
  x,y,z,w=b[i],b[-1-i],a[i],a[-1-i]
  if x==y: r += (z!=w)
  else: r += len({x,y}-{z,w})
r += (n%2 and a[n//2] != b[n//2])
print(r)