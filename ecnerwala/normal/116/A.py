n=int(input())
r,c=0,0
for i in range(n):
 a,b=map(int,input().split())
 c+=b-a
 r=max(r,c)
print(r)