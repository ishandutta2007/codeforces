import sys
def g(x):
 print(x,flush=True)
 v=int(input())
 if v:return v
 sys.exit()
m,n=map(int, input().split())
a=[g(1) for i in range(n)]
mi,ma=0,m+1
while 1:
 md=(mi+ma)//2
 v=g(md)*a[0]
 a=a[1:]+a[:1]
 if v<0:ma=md
 else:mi=md