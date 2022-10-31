R=lambda:list(map(int,input().split()))
n,x=R()
a=R()
print(x-len([i for i in a if i<x])+(1 if x in a else 0))