x, k=map(int, raw_input().split())
rounds=[True]*x
for i in xrange(k):
    l=map(int, raw_input().split())
    for j in l[1:]:
        rounds[j]=False
mini=maxi=0
i=1
while i<x:
    if rounds[i]:
        if i+1<x and rounds[i+1]:
            mini+=1
            maxi+=2
            i+=1
        else:
            mini+=1
            maxi+=1
    i+=1
print mini, maxi