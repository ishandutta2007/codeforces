n,m,a,b=list(map(int,input().split()))
print(min((n%m)*b,(m-(n%m))*a))