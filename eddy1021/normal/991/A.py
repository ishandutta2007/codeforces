a,b,c,n=list(map(int,input().split()))
x=a+b-c
print(n-x if c<=a and c<=b and x<n else -1)