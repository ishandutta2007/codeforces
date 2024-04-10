import math
n,k=list(map(int,input().split()))
print(10**k*(n//math.gcd(10**k,n)))