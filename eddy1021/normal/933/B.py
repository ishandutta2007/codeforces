p,k=list(map(int,input().split()))
a=[]
for i in range(99):
  v=p%k
  if v==0 or i%2 == 0:a.append(v)
  else:
    a.append(k-v)
    p+=k
  p//=k
  if p==0: break
print(len(a))
print(' '.join(list(map(str,a))))