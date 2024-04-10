n,a,x,b,y = map(int,input().split())
t=2*min((x-a)%n,(b-y)%n)
d=(b-a)%n
print("YNEOS"[not(n%2 and d+n<=t if d%2 else d<=t)::2])