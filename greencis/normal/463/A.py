r=lambda:map(int,input().split())
n,s=r()
ans=-1
s*=100
while n:
 n-=1
 x,y=r()
 x=x*100+y
 if x<=s:
  ans=max(ans,(s-x)%100)
print(ans)