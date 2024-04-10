s,n=map(int,input().split())
x,y=zip(*sorted(tuple(map(int,input().split())) for i in range(n)))
print(['NO','YES'][all(s+sum(y[:i])>x[i] for i in range(n))])