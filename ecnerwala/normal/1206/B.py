input()
p,n=0,2
for a in map(int,input().split()):
 x,y=abs(a-1),abs(a+1)
 p,n=min(p+x,n+y),min(n+x,p+y)
print(p)