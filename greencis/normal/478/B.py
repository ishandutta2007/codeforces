n,m=map(int,input().split())
mxc=n%m
mnc=m-mxc
mn=n//m
mx=mn+1
print(mxc*mx*(mx-1)//2 + mnc*mn*(mn-1)//2, (n-m)*(n-m+1)//2)