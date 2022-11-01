n=input()
ppl=[(map(int, raw_input().split()), i) for i in xrange(n)]
k=input()
tables=[]
for i, j in enumerate(map(int, raw_input().split())):
    tables.append((j, i))
from heapq import *
Q=[]
ans=0
output=[]
ppl.sort()
tables.sort()
idx=0
for i in xrange(len(tables)):
    while idx<len(ppl) and tables[i][0]>=ppl[idx][0][0]:
        heappush(Q, (-ppl[idx][0][1], ppl[idx][1]))
        idx+=1
    if Q:
        profit, group=heappop(Q)
        ans-=profit
        output.append((group, tables[i][1]))
print len(output), ans
print "\n".join(map(lambda x: "%d %d"%(x[0]+1, x[1]+1), output))