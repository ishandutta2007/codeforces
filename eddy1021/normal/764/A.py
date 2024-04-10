from fractions import * 
n,m,z=list(map(int,input().split()))
print(z*gcd(n,m)//n//m)