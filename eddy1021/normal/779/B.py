n,k=list(map(int,input().split()))
ans,c=0,0
while k>0 and n>0:
  if n % 10 == 0: k -= 1
  else: ans += 1
  n //= 10
  c += 1
print(ans if n>0 else max(0,c-1))