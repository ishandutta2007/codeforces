n,k=map(int,input().split())
s=sorted(map(ord,input()))
r=s[:1]
for c in s[1:]:
 if c>r[-1]+1:r.append(c)
print(-1 if len(r)<k else sum(r[:k])-96*k)