import sys
n,*a=sys.stdin.readlines()
n=int(n.split()[0])
for l in a:
 x,y=map(int,l.split())
 print((x+y)%2*(n*n+1)//2+(y+x*n-n+1)//2)