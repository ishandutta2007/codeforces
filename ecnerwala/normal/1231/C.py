import sys
n,m=map(int,input().split())
a=[[*map(int,input().split())] for _ in range(n)]
try:
 for i in range(n-1,-1,-1):
  for j in range(m-1,-1,-1):
   if a[i][j]==0:a[i][j]=min(a[i+1][j],a[i][j+1])-1
   if i+1<n:assert a[i][j]<a[i+1][j]
   if j+1<m:assert a[i][j]<a[i][j+1]
 print(sum(map(sum,a)))
except AssertionError:
 print(-1)