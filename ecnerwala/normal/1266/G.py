M,a=998244353,0
p=n=int(input())
for i in range(n-1):a,p=(a+p*(n-i-1)*(i+1)-p)%M,p*(n-i)%M
a=(p*(p-n+2)-a-a)%M
if a&1:a+=M
print(a//2)