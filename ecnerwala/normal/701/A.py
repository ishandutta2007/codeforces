n=int(input());a=list(map(int,input().split()));b=sorted(range(n),key=lambda v:a[v])
for i in range(n//2):print(b[i]+1,b[~i]+1)