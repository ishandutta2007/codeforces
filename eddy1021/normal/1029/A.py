n,k=list(map(int, input().split()))
t=input()
for i in range(1,n):
  if t[i:]==t[:n-i]:
    print(t+t[n-i:]*(k-1))
    break
else: print(t*k)