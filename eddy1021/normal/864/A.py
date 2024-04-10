n=int(input())
a=[int(input()) for i in range(n)]
if len(set(a))!=2 or len([i for i in a if i == a[0]])!=n//2:
  print('NO')
else:
  a=list(set(a))
  print('YES')
  print(a[0], a[1])