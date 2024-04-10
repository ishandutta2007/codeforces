N, L, R, X=map(int, raw_input().split())
A=map(int, raw_input().split())
ans=0
for i in xrange(1<<N):
    B=[]
    for j in xrange(N):
        if (i>>j)&1:
            B.append(A[j])
    if len(B)>=2 and L<=sum(B)<=R and max(B)-min(B)>=X:
        ans+=1
print ans