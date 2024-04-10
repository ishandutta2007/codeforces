n,k = map(int, input().split())
k = 240 - k
res = 0
for i in range(1,n+1):
 if k >= 5 * i:
   k -= 5 * i
   res += 1
print(res)