from itertools import *
n,m=map(int,input().split())
e = [tuple(int(s)-1 for s in input().split()) for _ in range(m)]
print(max(len(set(tuple(sorted([p[a],p[b]])) for a,b in e)) for p in permutations(i%6 for i in range(n))))