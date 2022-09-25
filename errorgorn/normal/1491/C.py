TC=int(input())
 
for tc in range(TC):
    n=int(input())
    arr=list(map(int,input().split()))
    
    curr=[0]*(n+5)
    
    ans=0
    
    for x in range(n):
        temp=curr[x]
        
        if (temp<arr[x]-1):
            ans+=arr[x]-1-temp
            temp+=arr[x]-1-temp
            
        curr[x+1]+=temp-arr[x]+1
        for y in range(x+2,min(n,x+arr[x]+1)):
            curr[y]+=1
        
    print(ans)