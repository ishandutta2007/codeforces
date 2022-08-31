n,k=map(int,input().split())
a=[*map(int,input().split())]
a=sorted(((a[i],i) for i in range(n)),reverse=True)[:k]
print(sum(v for v,i in a))
a=sorted(i for v,i in a)
a[-1]=n-1
print(' '.join(str(y-x) for x,y in zip([-1]+a,a)))