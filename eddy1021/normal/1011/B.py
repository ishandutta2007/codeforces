R=lambda:list(map(int,input().split()))
n,m=R()
a=R()
d={}
for i in a:d[i]=0
for i in a:d[i]+=1
b=1
while sum(d[i]//b for i in d)>=n: b+=1
print(b-1)