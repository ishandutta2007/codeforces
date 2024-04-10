import math
i=lambda:map(int,input().split())
n,k=i()
g=k
for a in i():g=math.gcd(g,a)
print(k//g)
print(*range(0,k,g))