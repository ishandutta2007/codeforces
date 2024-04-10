n,k=map(int,input().split())
l=2*k+1
r=[*range(n-(-n%l<k)*k,0,-l)]
print(len(r),*r)