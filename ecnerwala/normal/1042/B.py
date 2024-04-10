n=int(input())
v=[0]+[10**9]*7
for _ in range(n):
 c,s=input().split()
 c=int(c)
 s=sum(1<<(ord(x)-ord('A')) for x in s)
 for i in range(8):
  v[i|s]=min(v[i|s], v[i]+c)
if v[7]==10**9: v[7]=-1
print(v[7])