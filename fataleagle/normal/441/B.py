n, v=map(int, raw_input().split())
trees=[map(int, raw_input().split()) for i in xrange(n)]
fruits=[0]*3002
for a, b in trees:
    fruits[a]+=b
ans=0
left=0
for i in xrange(1, 3002):
    collect=min(v, left)
    ans+=collect
    now=min(v-collect, fruits[i])
    ans+=now
    left=fruits[i]-now
print ans