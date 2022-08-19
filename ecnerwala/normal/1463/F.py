from math import *
n,x,y=map(int,input().split());g=gcd(x,y);n,x,y,r,h=n//g,x//g,(x+y)//g,n%g,lambda n:max(f(n,0),f(n,1))
def f(n,s):
 d=[-n,-n];d[s]=0
 for i in range(y):d=[max(d[0],d[1]),d[0]+n//y+(i*x%y<n%y)]
 return d[s]
print(h(n+1)*r+h(n)*(g-r))