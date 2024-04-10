n,k=list(map(int,input().split()))
s=sorted(list(set(input().strip())))
a,g,p=0,0,0
for c in s:
  xx=ord(c)
  if xx>=p+2:a,g,p=a+xx-96,g+1,xx
  if g==k:break
print(-1 if g<k else a)