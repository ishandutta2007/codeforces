a=list(map(int,input().split()))
for i in range(99999):
  a[i%2]-=i+1
  if a[i%2]<0: break
print('Vladik'if a[0]<0 else'Valera')