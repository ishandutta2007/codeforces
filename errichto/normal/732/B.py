n,k=list(map(int,input().split()))
lis=list(map(int,input().split()))
counter=0
for i in range(n-1):
    if lis[i]+lis[i+1]<k:
        counter+=k-lis[i]-lis[i+1]
        lis[i+1]=k-lis[i]
print(counter)
print(*lis)