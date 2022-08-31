n,m=map(int,input().split())
from collections import *
a=[*Counter(input().split()).values()]
d=m//n
while d>0:
 if sum(c//d for c in a)>=n:break
 d-=1
print(d)