n,m,a,b=map(int,input().split())
print(n//m*min(b,m*a)+min((n%m)*a,b))