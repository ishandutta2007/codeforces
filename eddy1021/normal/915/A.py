R=lambda:list(map(int,input().split()))
n,k=R()
print(min(k//i if k%i==0 else k for i in R()))