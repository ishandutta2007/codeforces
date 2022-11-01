R=lambda:list(map(int,input().split()))
n,k=R()
t=4*n
s=0
for i in R():
  s+=i+i%2
  n-=i%2
print('NO'if s>t+t or (s==t+t and k==t and n>0) else 'YES')