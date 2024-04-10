R=lambda:list(map(int,input().split()))
n,k=R()
w=R()
print((sum((i+k-1)//k for i in w)+1)//2)