i=lambda:map(int,input().split())
n,m=i()
s=lambda a,b:{*range(a,b+1)}
v=s(1,m)
for _ in range(n):v-=s(*i())
print(len(v))
print(*v)