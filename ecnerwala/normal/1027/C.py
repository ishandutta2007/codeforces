import sys
from collections import *
l=sys.stdin.readlines()[2::2]
r=[]
for a in l:
 a=Counter(map(int,a.split()))
 s=sorted([k for k in a if a[k]>1]+[k for k in a if a[k]>3])
 r+=[*min(zip(s,s[1:]),key=lambda a:sum(a)**2/a[0]/a[1])]*2
print(*r)