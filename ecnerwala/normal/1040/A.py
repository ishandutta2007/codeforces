i=lambda:map(int,input().split())
n,*a=i()
a+=[min(a)]
s=[*i()]
t=s[::-1]
print((0,1)in zip(s,t)and-1or sum(a[y]for x,y in zip(s,t)if 1<x))