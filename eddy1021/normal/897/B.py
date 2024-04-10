k,p=list(map(int,input().split()))
a=0
for i in range(1,k+1):
  s=str(i)
  a=(a+int(s+s[::-1]))%p
print(a)