i=lambda:map(int,input().split())
n,d=i()
m,=i()
for _ in [0]*m:
 x,y=i()
 print("NYOE S"[-d<=x-y<=d and d<=x+y<=n+n-d::2])