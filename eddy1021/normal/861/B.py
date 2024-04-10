R=lambda:list(map(int,input().split()))
n,m=R()
c=[R()for i in range(m)]
a=list(set([(n-1)//i+1 for i in range(1,999)if all((k[0]-1)//i+1==k[1]for k in c)]))
print(a[0]if len(a)==1 else -1)