from random import randint
import math
n=int(input());
ans=[n]
for zz in range(20):
    x=randint(1,233)
    print("sqrt %d" % (x*x%n));
    y=int(input());
    if x==y:
        continue
    tmp=[]
    for t in ans:
        g=math.gcd(t,x+y)
        tmp.append(g),tmp.append(t//g)
    ans=set(tmp)
ans=set(ans)-{1}
print("!",len(ans),*ans,sep=' ')