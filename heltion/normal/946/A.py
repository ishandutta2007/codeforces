input()
A=list(map(int,input().split()))
A=[-x if x<0 else x for x in A]
print(sum(A))