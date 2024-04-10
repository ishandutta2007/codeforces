R=lambda:list(map(int,input().split()))
n,k=R()
print(sum(sorted(R())[:k]))