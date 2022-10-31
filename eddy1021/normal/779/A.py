input()
a=[0 for i in range(6)]
b=[0 for i in range(6)]
for i in list(map(int,input().split())): a[i]+=1
for i in list(map(int,input().split())): b[i]+=1
ans = 0
for i in range(6):
  if (a[i]+b[i])%2>0:
    print('-1')
    exit(0)
  ans += abs(a[i]-(a[i]+b[i])//2)
print(ans//2)