n=int(input())
t=[*map(int,input().split())]
v=[-1]+[i for i,x,y in zip(range(n),t,t[1:]) if x!=y]+[n-1]
v=[y-x for x,y in zip(v,v[1:])]+[0]
print(max(map(min,zip(v,v[1:])))*2)