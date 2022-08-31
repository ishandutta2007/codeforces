n=int(input())
from collections import *
c=defaultdict(list)
for i,a in enumerate(input().split()):
 c[a].append(i)
c=c.items
c1=[v[0] for k,v in c() if len(v)==1]
c3=[v[0] for k,v in c() if len(v)>2]
if len(c1)%2 and not c3: print('NO')
else:
 if len(c1)%2: c1.append(c3[0])
 r=['A']*n
 for v in c1[1::2]: r[v]='B'
 print('YES\n'+''.join(r))