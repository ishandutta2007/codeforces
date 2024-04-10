n,k=map(int,input().split())
a=sorted(list(map(int,input().split())))
i=0
while i<n and a[i]<=5-k:
 i+=1
print(i//3)