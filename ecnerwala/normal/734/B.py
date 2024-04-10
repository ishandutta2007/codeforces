a,b,c,d = map(int,input().split())
n = min(a,c,d)
a-=n
c-=n
d-=n
m = min(a,b)
print(n*256+m*32)