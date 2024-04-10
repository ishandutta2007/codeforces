R=lambda:list(map(int,input().split()))
input()
a=R()
b=sorted(list(R()),reverse=True)
p=0
for i in range(len(a)):
  if a[i]==0:
    a[i]=b[p]
    p+=1
print('Yes'if any(a[i]<=a[i-1] for i in range(1,len(a)))else'No')